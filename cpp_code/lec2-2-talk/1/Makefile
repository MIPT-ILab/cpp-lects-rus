result: stackuser1.o stackuser2.o stack.o
	ar -cruv libstack.a stackuser1.o stackuser2.o stack.o
	$(CXX) main.cc -L. -lstack -o $@

stack.o : stack.cc stack.hpp

stackuser1.o : stackuser1.cc stack.hpp

stackuser2.o : stackuser2.cc stack.hpp

.PHONY: clean
clean:
	rm -rf *.o *.a a.out result

