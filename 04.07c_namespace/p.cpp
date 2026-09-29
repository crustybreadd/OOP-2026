#include <stdio.h>

// global namespace
int x = 1;			
int y = 2;			

namespace abc		
{
	int y = 3;		
					

	int f(int u)	
	{
		int z = 3;	
					
					

		z = u;		
					
					

		z = y;		
					

		z = ::y;	
					
		
		z = x;		
					

		z = ::x;	
					
		
		return z;
	}
}
// global namespace

int main()
{
	int x;

	x = abc::f(4);

	printf("x: %d\n", x);
}