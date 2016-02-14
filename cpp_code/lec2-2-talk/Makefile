result: stackuser1.o stackuser2.o
	ar -cruv libstack.a stackuser1.o stackuser2.o
	$(CXX) main.cc -L. -lstack -o $@

stackuser1.o : stackuser1.cc stack.hpp

stackuser2.o : stackuser2.cc stack.hpp

.PHONY: clean
clean:
	rm -rf *.o *.a a.out result

