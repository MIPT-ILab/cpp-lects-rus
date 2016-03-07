# Drawer makefile

CXXFLAGS += -O2 -W

all : funcbitmap waves

waves : waves.cc sdlutil.o
	${CXX} waves.cc sdlutil.o ${CXXFLAGS} -lSDL -o $@

funcbitmap : funcbitmap.cc sdlutil.o
	${CXX} funcbitmap.cc sdlutil.o ${CXXFLAGS} -lSDL -o $@

sdlutil.o : sdlutil.cc sdlutil.hpp

.PHONY: clean
clean:
	rm -rf a.out waves funcbitmap *.o *.bmp
