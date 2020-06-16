CC = g++ $(CFLAGS)

CFLAGS = -g -O0 -Wno-unused -Wno-unused-function -Wno-unused-label -Wno-error -Wreturn-type -Wfatal-errors

default: compiler.y scanner.l parser.hpp INode.hpp Node.hpp Node.cpp driver.cpp
	flex -8 scanner.l
	bison -o compiler.cpp --defines=compiler.cpp.h -v compiler.y
	$(CC) $(CFLAGS) -o program compiler.cpp Node.cpp driver.cpp lex.yy.c

clean:
	rm lex* program compiler.c* compiler.out*
