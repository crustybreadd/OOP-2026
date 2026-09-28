#include <stdio.h>

int sum(int a, int b, int c = 0, int d = 0) // c and d have default values of 0
{
	return a + b + c + d;
}




int main()
{
	printf("1 + 2: %d\n", sum(1, 2));
	printf("1 + 2 + 3: %d\n", sum(1, 2, 3));
	printf("1 + 2 + 3 + 4: %d\n", sum(1, 2, 3, 4));
}