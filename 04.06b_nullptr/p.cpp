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
	// this will compile because NULL is defined as 0, which is an integer literal, 
	// and there is no overload of f that takes an integer literal
	f( nullptr);
}
