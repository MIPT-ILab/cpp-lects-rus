# trivial build system

ADDFLAGS = -g -O0 -Wno-unused -Wno-unused-function -Wno-unused-label -Wno-error -Wreturn-type -Wfatal-errors

.PHONY: all
all: program

program: driver.cpp lexer.o parser.o node.o
	$(CXX) $(ADDFLAGS) $(CXXFLAGS) -o program lexer.o parser.o node.o driver.cpp

parser.o: parser.hpp compiler.cpp.h compiler.cpp
	$(CXX) $(ADDFLAGS) $(CXXFLAGS) compiler.cpp -c -o parser.o

lexer.o: parser.hpp compiler.cpp.h lex.yy.c
	$(CXX) $(ADDFLAGS) $(CXXFLAGS) lex.yy.c -c -o lexer.o

node.o: INode.hpp Node.hpp Symtab.hpp Node.cpp
	$(CXX) $(ADDFLAGS) $(CXXFLAGS) Node.cpp -c -o node.o

compiler.cpp compiler.cpp.h: compiler.y
	bison -o compiler.cpp --defines=compiler.cpp.h -v compiler.y

lex.yy.c: scanner.l
	flex -8 scanner.l

.PHONY: clean
clean:
	rm -f lex* compiler.c* compiler.out* program *.o
