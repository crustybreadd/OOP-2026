// p1.c
#include <stdio.h>

extern int a;					// declared in p2.c
extern int b;					// declared in p2.c
extern int c;					// declared in p2.c

void f(void)
{
	int d = 4;
}

int main()
{
	int e = 5;

	printf("a: %d\n", a);

	printf("b: %d\n", b);

	printf("c: %d\n", c);

	printf("d: %d\n", d);

	printf("e: %d\n", e);
}