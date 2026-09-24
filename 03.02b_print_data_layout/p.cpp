#include <stdio.h>

class Song
{
	char title[20];
	int duration;

public:
	void print_data_layout()
	{
		printf("this:     %p\n", this); // print the address of the current object using the this pointer
		printf("title:    %p\n", title); // print the address of the title member variable
		printf("duration: %p\n", &duration); //print the address of the duration member variable

	}
};

int main()
{
	Song s1, s2, s3;

	//printf("s1: %p\n", &s1); // print the address of s1
	s1.print_data_layout(); // print the address of s1 using the this pointer
	printf("\n"); // print a newline for better readability

	//printf("s2: %p\n", &s2); // print the address of s2
	s2.print_data_layout(); // print the address of s2 using the this pointer
	printf("\n"); 

	//printf("s3: %p\n", &s3); // print the address of s3
	s3.print_data_layout(); // print the address of s3 using the this pointer
	printf("\n");


}
