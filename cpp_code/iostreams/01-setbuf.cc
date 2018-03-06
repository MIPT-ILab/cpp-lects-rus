#include <cstdio>
#include <ctime>

using std::fprintf;

void delay(int seconds)
{
	time_t start, current;
	time(&start);
	do { time(&current); } while ((current - start) < seconds);
}

int main ()
{
	// buffered IO
	setvbuf (stdout, NULL, _IOFBF, 1024);
	
	// unbuffered IO
	// setbuf (stdout, NULL);
	
	fprintf (stdout, "%s, ", "Hello");
	delay(5);
	fprintf (stdout, "%s!\n", "world");
}

