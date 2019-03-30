// problem mk common types

#pragma once

enum reg_t {
  A = 0, B, C, D, RLAST
};

enum opcode_t {
  MOVI = 0, ADD, SUB, MUL, DIV, IN, OUT, OPLAST
};

union operand_t {
  struct { int rd, rs; } ops;
  int rop;
  int imm;
};

struct instr_t {
  enum opcode_t opcode;
  union operand_t opnd;
};

typedef unsigned char reg_state_t;
