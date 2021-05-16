//------------------------------------------------------------------------------
//
// Vector addition, SYCL way
//
//------------------------------------------------------------------------------
//
// This file is licensed after LGPL v3
// Look at: https://www.gnu.org/licenses/lgpl-3.0.en.html for details
//
//------------------------------------------------------------------------------

#include <CL/sycl.hpp>

#include <iostream>
#include <vector>

constexpr auto sycl_read = cl::sycl::access::mode::read;
constexpr auto sycl_write = cl::sycl::access::mode::write;

constexpr int LIST_SIZE = 1024 * 1024 * 2;
using arr_t = std::vector<cl::sycl::cl_int>;

// class is used for kernel name
template <typename T> class simple_vector_add;

class ocl_ctx_t {
  cl::sycl::queue deviceQueue;

public:
  ocl_ctx_t(const cl::sycl::device_selector &sel) : deviceQueue(sel) {}

  void print_info(std::ostream &os) const {
    auto device = deviceQueue.get_device();
    os << device.get_info<cl::sycl::info::device::name>() << "\n";
    os << "Driver version: "
       << device.get_info<cl::sycl::info::device::driver_version>() << "\n";
    os << device.get_info<cl::sycl::info::device::opencl_c_version>() << "\n";
  }

  template <typename T>
  void process_buffers(T const *pa, T const *pb, T *pc, size_t sz);
};

int main() {
  arr_t A(LIST_SIZE), B(LIST_SIZE), C(LIST_SIZE);
  std::cout << "Welcome to vector addition" << std::endl;

  try {
    cl::sycl::gpu_selector gpsel;
    ocl_ctx_t ct{gpsel};
    ct.print_info(std::cout);

    std::cout << "Initializing" << std::endl;
    for (int i = 0; i < LIST_SIZE; i++) {
      A[i] = i;
      B[i] = LIST_SIZE - i;
    }

    ct.process_buffers(A.data(), B.data(), C.data(), LIST_SIZE);

    std::cout << "Done, checking with host results" << std::endl;
    for (int i = 0; i < LIST_SIZE; ++i)
      if (C[i] != A[i] + B[i]) {
        std::cerr << "At index: " << i << ". ";
        std::cerr << C[i] << " != " << A[i] + B[i] << "\n";
        abort();
      }

    std::cout << "Everything is correct" << std::endl;
  } catch (cl::sycl::exception const &err) {
    std::cerr << "ERROR: " << err.what() << ":\n";
    return -1;
  }
}

template <typename T>
void ocl_ctx_t::process_buffers(T const *pa, T const *pb, T *pc, size_t sz) {
  cl::sycl::range<1> numOfItems{sz};
  cl::sycl::buffer<T, 1> bufferA(pa, numOfItems);
  cl::sycl::buffer<T, 1> bufferB(pb, numOfItems);
  cl::sycl::buffer<T, 1> bufferC(pc, numOfItems);

  bufferA.set_final_data(nullptr);
  bufferB.set_final_data(nullptr);

  std::cout << "Calculating" << std::endl;
  deviceQueue.submit([&](cl::sycl::handler &cgh) {
    auto A = bufferA.template get_access<sycl_read>(cgh);
    auto B = bufferB.template get_access<sycl_read>(cgh);
    auto C = bufferC.template get_access<sycl_write>(cgh);

    auto kern = [A, B, C](cl::sycl::id<1> wiID) {
      C[wiID] = A[wiID] + B[wiID];
    };
    cgh.parallel_for<class simple_vector_add<T>>(numOfItems, kern);
  });
}
