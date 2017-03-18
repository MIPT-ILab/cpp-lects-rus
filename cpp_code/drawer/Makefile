# Drawer makefile

CXXFLAGS += -O2 -Wall -Wextra

all : funcbitmap waves julia

julia : julia.cc sdlutil.o
	${CXX} julia.cc sdlutil.o ${CXXFLAGS} -lSDL -o $@

waves : waves.cc sdlutil.o
	${CXX} waves.cc sdlutil.o ${CXXFLAGS} -lSDL -o $@

funcbitmap : funcbitmap.cc sdlutil.o
	${CXX} funcbitmap.cc sdlutil.o ${CXXFLAGS} -lSDL -o $@

sdlutil.o : sdlutil.cc sdlutil.hpp

.PHONY: clean
clean:
	rm -rf a.out waves funcbitmap *.o *.bmp
