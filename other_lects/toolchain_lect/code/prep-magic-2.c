#include <assert.h>
#include "myheader.h"

enum type_t {
  OP_IGNORED = 0x0, OP_SRC = 0x1000,
  OP_DST = 0x2000, OP_DSTSRC = 0x3000
};

bool is_op_src (enum type_t a) {
  return (a & OP_SRC);
}

int main (void)
{
  enum type_t x = OP_DSTSRC;
  assert (is_op_src(x));
}

