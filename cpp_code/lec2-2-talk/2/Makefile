result : main.cc stackuser1.o stackuser2.o stack.hpp
	$(CXX) $(CXXFLAGS) main.cc stackuser1.o stackuser2.o -o $@

stackuser1.o : stackuser1.cc stack.hpp
	$(CXX) $(CXXFLAGS) -c stackuser1.cc -frepo -o $@

stackuser2.o : stackuser2.cc stack.hpp
	$(CXX) $(CXXFLAGS) -c stackuser2.cc -frepo -o $@

.PHONY: clean
clean:
	rm -rf *.o *.rpo *.a a.out result

