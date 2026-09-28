#include <stdio.h>

// default must be the last parameter in the function declaration
// cannot do int f(int x = 5, int y) // error: default argument missing for parameter 'y'
int f(int x, int y = 5) // y has a default value of 5
{
	return x * y;
}




int main()
{
	printf("f(2) = %d\n", f(2));
	printf("f(2, 3) = %d\n", f(2, 3)); // default value of y is overridden by 3
}