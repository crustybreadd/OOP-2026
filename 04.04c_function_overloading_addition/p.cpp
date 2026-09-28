#include <stdio.h>

// provide functions add here

// This function takes two integers as parameters
// this adds two integers and returns the result
int add(int a, int b)
{
	return a + b;
}

// This function takes two doubles as parameters
// this adds two doubles and returns the result
double add(double a, double b)
{
	return a + b;
}


int main()
{
	printf("int addition: %d\n", add(1, 2));
	printf("double addition: %.2lf\n", add(1., 2.));
}