#include <stdio.h>


int main()
{
	auto x = 5;

	// error because y is not initialized, so the compiler cannot deduce its type
	//auto y;

	// correct because y is initialized with x, so the compiler can deduce its type to be int
	auto y = 0;

	y = x;

	printf("y: %ld\n", y);
	printf("x: %ld\n", x);
}
