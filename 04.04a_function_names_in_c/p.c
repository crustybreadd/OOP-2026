#include <stdio.h>


// This function takes an integer as a parameter
// a is a copy of the argument passed to the function
void f(int a)
{
	printf("Function f(%d)\n", a);
}


// This function takes two integers as parameters
// a and b are copies of the arguments passed to the function
void f(int a, int b)
{
	printf("Function f(%d, %d)\n", a, b);
}

int main()
{
	// this wont work because the function f is overloaded and the compiler cannot determine which version of the function to call
	f(5);
	f(1, 2);
}