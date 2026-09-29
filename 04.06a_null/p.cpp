#include <stdio.h>

void f(int i)
{
	printf("f(integer)\n");
}

void f(int *p)
{
	printf("f(pointer)\n");
}

int main()
{
	// this wont compile because NULL is defined as 0, which is an integer literal, 
	//and there is no overload of f that takes an integer literal
	f( NULL);
	
	// To fix this, we can use a nullptr instead of NULL
	//f( nullptr);
}
