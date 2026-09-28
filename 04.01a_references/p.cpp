#include <stdio.h>

int main()
{
	int a = 1;
	int b = 2;

	int *p = &a;				
	int &r = b;					

	printf("a:  %d\n", a);		
	printf("*p: %d\n", *p);		
	printf("b:  %d\n", b);		
	printf("r:  %d\n\n", r);	

	*p = 3;						
	r = 4;						

	printf("a:  %d\n", a);		
	printf("*p: %d\n", *p);		
	printf("b:  %d\n", b);		
	printf("r:  %d\n\n", r);	

	p = &b;						
	*p = 5;						

	printf("a:  %d\n", a);		
	printf("*p: %d\n", *p);		
	printf("b:  %d\n", b);		
	printf("r:  %d\n\n", r);	

	r = a;						
	r = 6;						

	printf("a:  %d\n", a);		
	printf("*p: %d\n", *p);		
	printf("b:  %d\n", b);		
	printf("r:  %d\n", r);		
}
