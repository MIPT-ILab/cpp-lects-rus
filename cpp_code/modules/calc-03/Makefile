# trivial build system

CXX = clang++

BASEFLAGS = -g -O0 -Wno-unused -Wno-unused-function -Wno-unused-label -Wno-error -Wreturn-type -Wfatal-errors

ADDFLAGS = $(BASEFLAGS) --std=c++20 -fmodules --stdlib=libc++

PREFLAGS = $(ADDFLAGS) --precompile

.PHONY: all
all: program

program: driver.cpp lexer.o parser.o node.o parser.pcm
	$(CXX) $(ADDFLAGS) $(CXXFLAGS) -o program -fmodule-file=parser.pcm lexer.o parser.o node.o driver.cpp parser.pcm

parser.o: parser.pcm compiler.cpp.h compiler.cpp yyret.h
	$(CXX) $(ADDFLAGS) $(CXXFLAGS) -fmodule-file=parser.pcm compiler.cpp -c -o parser.o

lexer.o: parser.pcm compiler.cpp.h lex.yy.c yyret.h
	$(CXX) $(ADDFLAGS) $(CXXFLAGS) -x c++ lex.yy.c -fmodule-file=parser.pcm -c -o lexer.o

node.o: Node.cpp node.pcm symtab.pcm
	$(CXX) $(ADDFLAGS) $(CXXFLAGS) -fmodule-file=node.pcm -fmodule-file=symtab.pcm Node.cpp -c -o node.o

node.pcm: Node.cppm
	$(CXX) $(PREFLAGS) $(CXXFLAGS) Node.cppm -o node.pcm

parser.pcm: parser.cppm node.pcm compiler.cpp.h yyret.h
	$(CXX) $(PREFLAGS) $(CXXFLAGS) parser.cppm -fmodule-file=node.pcm -o parser.pcm

symtab.pcm: Symtab.cppm node.pcm
	$(CXX) $(PREFLAGS) $(CXXFLAGS) Symtab.cppm -fmodule-file=node.pcm -o symtab.pcm

compiler.cpp compiler.cpp.h: compiler.y
	bison -o compiler.cpp --defines=compiler.cpp.h -v compiler.y

lex.yy.c: scanner.l
	flex -8 scanner.l

.PHONY: clean
clean:
	rm -f lex* compiler.c* compiler.out* program *.o *.pcm
