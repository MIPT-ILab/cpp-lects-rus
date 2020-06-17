# trivial build system

CXX = clang++

ADDFLAGS = --std=c++20 -fmodules --stdlib=libc++

PREFLAGS = $(ADDFLAGS) --precompile

.PHONY: all
all: first-main second-main

first-main: first-main.cc first_module.pcm
	$(CXX) $(ADDFLAGS) $(CXXFLAGS) -fmodule-file=first_module.pcm -o $@ first-main.cc first_module.pcm

second-main: second-main.cc combined_module.pcm
	$(CXX) $(ADDFLAGS) $(CXXFLAGS) -fmodule-file=combined_module.pcm -o $@ second-main.cc first_module.pcm second_module.pcm

first_module.pcm: first_module.cppm
	$(CXX) $(PREFLAGS) $(CXXFLAGS) first_module.cppm -o first_module.pcm

second_module.pcm: second_module.cppm
	$(CXX) $(PREFLAGS) $(CXXFLAGS) second_module.cppm -o second_module.pcm

combined_module.pcm: combined_module.cppm first_module.pcm second_module.pcm
	$(CXX) $(PREFLAGS) $(CXXFLAGS) combined_module.cppm -fmodule-file=first_module.pcm -fmodule-file=second_module.pcm -o combined_module.pcm


.PHONY: clean
clean:
	rm -f *-main *.pcm *.o
