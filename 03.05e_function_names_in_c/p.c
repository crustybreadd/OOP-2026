#include <stdio.h>


void f(int a)
{
	printf("Function f(%d)\n", a);
}

void f(int a, int b)
{
	printf("Function f(%d, %d)\n", a, b);
}

int main()
{
	f(5);
	f(1, 2);
}