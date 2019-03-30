// problem MK sample solution

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "problem_mk.h"

void
execute_instr(struct reg_state_t *st, struct instr_t instr) {
  // TODO: your code here
}

struct instr_t
decode_instr(unsigned char cmd) {
  struct instr_t instr;

  // TODO: your code here

  return instr;
}

void
execute_program(FILE *prog) {
  unsigned command;
  struct reg_state_t regs[RLAST];
  
  while (fscanf(prog, "%x", &command) == 1) {
    struct instr_t instr;
    unsigned char cmd = command & 0xff;    
    assert(cmd == command);
    instr = decode_instr(cmd);
    execute_instr(regs, instr);
  }
}

int
main(int argc, char **argv) {
  FILE *prog;
  
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <programm>\n", argv[0]);
    abort();
  }
  
  prog = fopen(argv[1], "r");
  if (NULL == prog) {
    fprintf(stderr, "Usage: %s <programm>\n", argv[0]);
    fprintf(stderr, "Where file with programm shall exist\n");
    abort();
  }
  
  execute_program(prog);
  
  fclose(prog);
}