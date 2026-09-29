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
	f( nullptr);
}
