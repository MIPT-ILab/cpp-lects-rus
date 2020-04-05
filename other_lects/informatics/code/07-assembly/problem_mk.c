#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

enum reg_t {
  A = 0, B, C, D, RLAST
};

enum opcode_t {
  MOVI = 0, ADD = 8, SUB = 9, MUL = 10, DIV = 11, IN, OUT, OPLAST
};

union operand_t {
  struct {
    int rd, rs;
  } ops;
  int rop;
  int imm;
};

struct instr_t {
  enum opcode_t opcode;
  union operand_t opnd;
};

struct reg_state_t {
  unsigned char data;
  unsigned char init;
  // ???
};

enum {
  MOVMASK = (1 << 7),
  INOUTMASK = (1 << 6),
  IOSHIFT = 2,
  INOPC = 0x30,
  INOUTOP = 0x3,
  RSSHIFT = 0,
  RDSHIFT = 2,
  RMASK = 0x3,
  OPCSHIFT = 4,
};

static unsigned char
exec_binop(enum opcode_t opc, unsigned char rd, unsigned char rs) {
  switch(opc) {
    case ADD:
      return rd + rs;
    case SUB:
      return rd - rs;
    case MUL:
      return rd * rs;
    case DIV:
      return rd / rs;
    default:
      fprintf(stderr, "Binop opcode error: %d\n", opc);
      abort();
  }
}

static void
execute_instr(struct reg_state_t *st, struct instr_t instr) {
  switch(instr.opcode) {
    case MOVI: 
      {
        st[D].data = instr.opnd.imm;
        break;
      }
    case ADD:
    case SUB:
    case MUL:
    case DIV:
      {
        int rd = instr.opnd.ops.rd;
        int rs = instr.opnd.ops.rs;
        st[rd].data = exec_binop(instr.opcode, st[rd].data, st[rs].data);
        break;
      }
    case IN:
      {
        int d, res;
        res = scanf("%d", &d);
        assert(res == 1);
        st[instr.opnd.rop].data = d & 0xFF;
        break;
      }
    case OUT:
      {
        int d = st[instr.opnd.rop].data;
        printf("%d\n", d);
        break;      
      }
    default:
      {
        fprintf(stderr, "Execution opcode error: %d\n", instr.opcode);
        abort();
      }    
  }
}

static struct instr_t
decode_arith(unsigned char cmd) {
  struct instr_t instr;
  instr.opnd.ops.rs = (cmd >> RSSHIFT) & RMASK;
  instr.opnd.ops.rd = (cmd >> RDSHIFT) & RMASK;
  instr.opcode = (cmd >> OPCSHIFT);
  if (instr.opcode > DIV) {
    fprintf(stderr, "Opcode error: 0x%x\n", cmd);
    abort();
  }
  return instr;
}

static struct instr_t
decode_instr(unsigned char cmd) {
  struct instr_t instr;

  // 1. May be MOV
  if ((cmd & MOVMASK) == 0) {
    instr.opcode = MOVI;
    instr.opnd.imm = cmd;
  }
  // 2. IN or OUT
  else if ((cmd & INOUTMASK) == INOUTMASK) {
    if ((cmd >> IOSHIFT) == INOPC) {
      instr.opcode = IN;
    }
    else {
      instr.opcode = OUT;
    }
    instr.opnd.rop = cmd & INOUTOP;
  }
  // 3. Arithmetics
  else
    instr = decode_arith(cmd);

  return instr;
}

static void
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
    fprintf(stderr, "Got param: %s\n", argv[1]);
    perror("Can not open file for reading");
    fprintf(stderr, "\n");
    fprintf(stderr, "Usage: %s <programm>\n", argv[0]);
    fprintf(stderr, "Where file with programm shall exist\n");
    abort();
  }
  
  execute_program(prog);
  
  fclose(prog);
}

