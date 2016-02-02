result: maxuser1.o maxuser2.o max.o
	ar -cruv libmax.a maxuser1.o maxuser2.o max.o
	$(CXX) --std=c++14 main.cc -L. -lmax -o $@

maxuser1.o : maxuser1.cc max.hpp

maxuser2.o : maxuser2.cc max.hpp

max.o : max.cc max.hpp

.PHONY: clean
clean:
	rm -rf *.o *.a a.out result
