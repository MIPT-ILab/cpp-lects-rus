//------------------------------------------------------------------------------
//
// Matrix multiplication with local memory kernel (SYCL vs serial CPU)
//
//------------------------------------------------------------------------------
//
// This file is licensed after LGPL v3
// Look at: https://www.gnu.org/licenses/lgpl-3.0.en.html for details
//
//------------------------------------------------------------------------------

#include <CL/sycl.hpp>

#include <cassert>
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>

namespace chrono = std::chrono;

#if defined(SIMPLEST)
#define TS 1
#else
#define TS 16
#endif

#if defined(SIMPLEST) && !defined(MEASURE_NORMAL)
#define MEASURE_NORMAL 1
#endif

constexpr auto sycl_read = cl::sycl::access::mode::read;
constexpr auto sycl_write = cl::sycl::access::mode::write;
constexpr auto sycl_rw = cl::sycl::access::mode::read_write;
constexpr auto sycl_local = cl::sycl::access::target::local;
constexpr auto sycl_local_fence = cl::sycl::access::fence_space::local_space;

// class is used for kernel name
class mxm_kernel;

// simplest smoke test
#if defined(SIMPLEST)

#define AXVAL 3
#define AYVAL 2
#define BYVAL 1

// if we do not need to do ineffective normal multiplications,
// default sizes are big
#elif !defined(MEASURE_NORMAL)

#if !defined(AXVAL)
#define AXVAL 256 * 10
#endif

#if !defined(AYVAL)
#define AYVAL 256 * 8
#endif

#if !defined(BYVAL)
#define BYVAL 256 * 6
#endif

#else

#if !defined(AXVAL)
#define AXVAL 256 * 5
#endif

#if !defined(AYVAL)
#define AYVAL 256 * 4
#endif

#if !defined(BYVAL)
#define BYVAL 256 * 3
#endif

#endif

constexpr int BIG_AX = AXVAL;
constexpr int BIG_AY = AYVAL;
constexpr int BIG_BY = BYVAL;

// A[AX][AY] * B[AY][BY] = C[AX][BY]
void matrix_mult_normal(const int *A, const int *B, int *C, int AX, int AY,
                        int BY) {
  int i, j, k;
  for (i = 0; i < AX; i++) {
    for (j = 0; j < BY; j++) {
      int acc = 0;
      for (k = 0; k < AY; k++)
        acc += A[i * AY + k] * B[k * BY + j];
      C[i * BY + j] = acc;
    }
  }
}

// to exclude silly errors
void smoketest() {
  int a[3][2] = {{1, 2}, {3, 4}, {5, 6}};
  int b[2][1] = {{1}, {2}};
  int c[3][1];

  matrix_mult_normal(&a[0][0], &b[0][0], &c[0][0], 3, 2, 1);

  bool res = (c[0][0] == 5) && (c[1][0] == 11) && (c[2][0] == 17);
  if (!res) {
    std::cerr << "Smoke test failed!\n";
    std::cerr << "Wrong result:\n";
    for (int i = 0; i < 3; ++i)
      std::cerr << c[i][0] << " ";
    std::cerr << "\n";
    std::cerr << "Correct result:\n";
    std::cerr << 5 << " " << 11 << " " << 17 << "\n";
    abort();
  }
}

void matrix_rand_init(int *arr, int sz) {
  static std::mt19937_64 mt_source;
  std::uniform_int_distribution<int> dist(0, 10);
  for (int i = 0; i < sz; ++i)
    arr[i] = dist(mt_source);
}

void test() {
#if !defined(SIMPLEST)
  int(*a)[BIG_AY] = new int[BIG_AX][BIG_AY];
  int(*b)[BIG_BY] = new int[BIG_AY][BIG_BY];
  int(*c)[BIG_BY] = new int[BIG_AX][BIG_BY];
  int(*cref)[BIG_BY] = new int[BIG_AX][BIG_BY];

  matrix_rand_init(&a[0][0], BIG_AX * BIG_AY);
  matrix_rand_init(&b[0][0], BIG_AY * BIG_BY);

#else
  int a[BIG_AX][BIG_AY] = {{1, 2}, {3, 4}, {5, 6}};
  int b[BIG_AY][BIG_BY] = {{1}, {2}};
  int c[BIG_AX][BIG_BY];
  int cref[BIG_AX][BIG_BY];
#endif

  chrono::high_resolution_clock::time_point tstart, tfin;

#if MEASURE_NORMAL
  tstart = chrono::high_resolution_clock::now();
  matrix_mult_normal(&a[0][0], &b[0][0], &cref[0][0], BIG_AX, BIG_AY, BIG_BY);
  tfin = chrono::high_resolution_clock::now();
  std::cout
      << "Normal calculation time: "
      << chrono::duration_cast<chrono::milliseconds>(tfin - tstart).count()
      << std::endl;
#endif

  { // need this additional scope to properly return data from buffers
    tstart = chrono::high_resolution_clock::now();
    cl::sycl::gpu_selector gpsel;
    cl::sycl::queue deviceQueue{gpsel};

    cl::sycl::range<2> Asz{BIG_AX, BIG_AY};
    cl::sycl::range<2> Bsz{BIG_AY, BIG_BY};
    cl::sycl::range<2> Csz{BIG_AX, BIG_BY};
    cl::sycl::range<2> Locsz{TS, TS};

    cl::sycl::buffer<int, 2> bufferA(&a[0][0], Asz);
    cl::sycl::buffer<int, 2> bufferB(&b[0][0], Bsz);
    cl::sycl::buffer<int, 2> bufferC(&c[0][0], Csz);

    bufferA.set_final_data(nullptr);
    bufferB.set_final_data(nullptr);

    tfin = chrono::high_resolution_clock::now();
    std::cout
        << "SYCL setup time: "
        << chrono::duration_cast<chrono::milliseconds>(tfin - tstart).count()
        << std::endl;

    tstart = chrono::high_resolution_clock::now();

    deviceQueue.submit([&](cl::sycl::handler &cgh) {
      auto A = bufferA.template get_access<sycl_read>(cgh);
      auto B = bufferB.template get_access<sycl_read>(cgh);
      auto C = bufferC.template get_access<sycl_write>(cgh);

      // local memory
      cl::sycl::accessor<int, 2, sycl_rw, sycl_local> Asub(Locsz, cgh);
      cl::sycl::accessor<int, 2, sycl_rw, sycl_local> Bsub(Locsz, cgh);

      auto kernmul = [=](cl::sycl::nd_item<2> it) {
        int row = it.get_local_id(0);
        int col = it.get_local_id(1);
        int globalRow = it.get_global_id(0);
        int globalCol = it.get_global_id(1);
        int numTiles = BIG_AY / TS;

        int sum = 0;

        for (int t = 0; t < numTiles; t++) {
          int tiledRow = TS * t + row;
          int tiledCol = TS * t + col;
          Asub[col][row] = A[globalRow][tiledCol];
          Bsub[col][row] = B[tiledRow][globalCol];
          it.barrier(sycl_local_fence);

          for (int k = 0; k < TS; k++)
            sum += Asub[k][row] * Bsub[col][k];
          it.barrier(sycl_local_fence);
        }

        C[globalRow][globalCol] = sum;
      };

      cgh.parallel_for<mxm_kernel>(
          cl::sycl::nd_range<2>{cl::sycl::range<2>(BIG_AX, BIG_BY),
                                cl::sycl::range<2>(TS, TS)},
          kernmul);
    });

    deviceQueue.wait();
    tfin = chrono::high_resolution_clock::now();

    std::cout
        << "SYCL calculation time: "
        << chrono::duration_cast<chrono::milliseconds>(tfin - tstart).count()
        << std::endl;
  }

#if defined(SIMPLEST)
  std::cout << "CSYCL: {" << c[0][0] << ", " << c[1][0] << ", " << c[2][0]
            << "} " << std::endl;
  std::cout << "CREF: {" << cref[0][0] << ", " << cref[1][0] << ", "
            << cref[2][0] << "} " << std::endl;
#endif

#if MEASURE_NORMAL
  for (int i = 0; i < BIG_AX; ++i)
    for (int j = 0; j < BIG_BY; ++j)
      if (cref[i][j] != c[i][j]) {
        std::cerr << i << ": " << c[i][j] << " != " << cref[i][j] << std::endl;
        abort();
      }
  std::cout << "Check against normal passed, matrices multiplied ok"
            << std::endl;
#endif

#if !defined(SIMPLEST)
  delete[] a;
  delete[] b;
  delete[] c;
  delete[] cref;
#endif
}

int main() {
  smoketest();
  std::cout << "Welcome to matrix multiplication" << std::endl;
  std::cout << "[ " << BIG_AX << " x " << BIG_AY << " ] * [ " << BIG_AY << " x "
            << BIG_BY << " ]" << std::endl;

  try {
    test();
  } catch (cl::sycl::exception const &err) {
    std::cerr << "ERROR: " << err.what() << ":\n";
    return -1;
  }
  std::cout << "DONE, BYE\n";
}

