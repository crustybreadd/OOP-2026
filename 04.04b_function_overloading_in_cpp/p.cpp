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
	// this works because the c++ compiler can determine which version of the function to call based on the number of arguments passed to the function
	// This is function overloading — a C++-only feature
	// The C compiler does not support function overloading, so this code will not compile in C
	f(5);
	f(1, 2);
}