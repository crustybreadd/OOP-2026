#include <stdio.h>


int main()
{
	// auto type deduction will deduce the type of x to be int
	auto x = 5;

	printf("sizeof(5): %ld\n", sizeof(5));
	printf("sizeof(x): %ld\n", sizeof(x));
}
