#include <stdio.h>

class Song
{
	char title[20];
	int duration;

public:
	void print_this()
	{
		printf("this: %p\n", this); // print the address of the current object using the this pointer
	}
};

int main()
{
	Song s1, s2, s3;
	s1.print_this(); // print the address of s1 using the this pointer
	s2.print_this(); // print the address of s2 using the this pointer
	s3.print_this(); // print the address of s3 using the this pointer


}
