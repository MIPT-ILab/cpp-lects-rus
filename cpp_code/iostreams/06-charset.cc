#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <system_error>

using std::cerr;
using std::cout;
using std::endl;
using std::fclose;
using std::fopen;
using std::fprintf;
using std::ios_base;
using std::ofstream;
using std::ostream;
using std::setw;
using std::system_error;

void __attribute__((noinline))
do_other_job_old(FILE*) {
}

void __attribute__((noinline))
do_other_job_new(ostream&) {
}

int
oldschool() {
  FILE *charfl = fopen("charset.txt", "rw");
  if (!charfl)
    return -1;
  
  for (int i = 32; i != 256; ++i)
    fprintf(charfl, "value: %3d char: %c", 
            i, static_cast<char>(i));
  do_other_job_old(charfl);
  fclose(charfl);
  return 0;
}

void
newone() {
  ofstream charfl; 
  charfl.exceptions(ofstream::failbit | ofstream::badbit);
  charfl.open("charset.txt", ofstream::out | ofstream::in); // now this throws
  for (int i = 32; i != 256; ++i)
    charfl << "value: " << setw(3) << i << " "
           << "char: " << static_cast<char>(i) << endl;
  do_other_job_new(charfl);
  charfl.close();
}

int
main() {
  if (0 == oldschool())
    cout << "Delete charset.txt to see how error handling works" << endl;

  try {
    newone();
    cout << "Writing charset done" << endl;
  } catch (ios_base::failure& e) {
    cerr << "IOS failure: " << e.what() << endl; 
  } catch (system_error& e) {
    cerr << "System error: " << e.code().message() << endl;
  }
}
