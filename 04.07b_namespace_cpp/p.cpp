#include <stdio.h>

int x = 1;

namespace abc
{
	int x = 2;

	namespace def
	{
		int x = 3;
	}
}

int main()
{
	printf("%d\n", x); // prints 1
	printf("%d\n", abc::x); // prints 2
	printf("%d\n", abc::def::x); // prints 3
}


