#include <stdio.h>

// pointer version
/*
void g(float* x, float *y)
{
	*x += 2 * (*y);
	*y = *y + (*y);
}

int main()
{
	float x = 5.5;
	float y = 7.0;

	g(&x, &y);

	printf("x: %.02f\n", x);
	printf("y: %.02f\n", y);
}
*/

// reference version
void g(float &x, float &y)
{
	x += 2 * (y);
	y = y + (y);
}

int main()
{
	float x = 5.5;
	float y = 7.0;

	g(x, y);

	printf("x: %.02f\n", x);
	printf("y: %.02f\n", y);
}