# trivial build system

CXX = clang++

ADDFLAGS = --std=c++20 -fmodules --stdlib=libc++

# you may try add -fno-rtti here and look what will happen!
PREFLAGS = $(ADDFLAGS) --precompile

.PHONY: all
all: first-main second-main third-main fourth-main

.PHONY: run
run: first-main second-main third-main fourth-main
	./first-main
	./second-main
	./third-main
	./fourth-main

first-main: first-main.cc first_module.pcm
	$(CXX) $(ADDFLAGS) $(CXXFLAGS) -fmodule-file=first_module.pcm first_module.pcm -o $@ first-main.cc

second-main: second-main.cc first_module.pcm
	$(CXX) $(ADDFLAGS) $(CXXFLAGS) -fmodule-file=first_module.pcm first_module.pcm -o $@ second-main.cc

third-main: third-main.cc first_module.pcm
	$(CXX) $(ADDFLAGS) $(CXXFLAGS) -fmodule-file=first_module.pcm first_module.pcm -o $@ third-main.cc

fourth-main: fourth-main.cc second_module.pcm second_module_impl.o
	$(CXX) $(ADDFLAGS) $(CXXFLAGS) -fmodule-file=second_module.pcm second_module_impl.o -o $@ fourth-main.cc

first_module.pcm: first_module.cppm
	$(CXX) $(PREFLAGS) $(CXXFLAGS) first_module.cppm -o first_module.pcm

second_module.pcm second_module_impl.o: second_module.cppm second_module_impl.cc
	$(CXX) $(PREFLAGS) $(CXXFLAGS) second_module.cppm -o second_module.pcm
	$(CXX) $(ADDFLAGS) $(CXXFLAGS) -fmodule-file=second_module.pcm -c -o second_module_impl.o second_module_impl.cc

.PHONY: clean
clean:
	rm -f *-main *.pcm *.o
