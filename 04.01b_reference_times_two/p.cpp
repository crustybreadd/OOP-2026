#include <stdio.h>

// This function takes a reference to an integer as a parameter
void f(int &r) // r is a reference to an integer
{
	r *= 2;
}




int main()
{
	int a = 1;

	f(a);

	printf("a: %d\n", a);

}