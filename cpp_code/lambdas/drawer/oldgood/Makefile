# Drawer makefile

CXXFLAGS += -O2 -Wall -Wextra

all : funcbitmap

funcbitmap : funcbitmap.cc sdlutil.o
	${CXX} funcbitmap.cc sdlutil.o ${CXXFLAGS} -lSDL -o $@

sdlutil.o : sdlutil.cc sdlutil.hpp

.PHONY: clean
clean:
	rm -rf a.out waves funcbitmap *.o *.bmp
