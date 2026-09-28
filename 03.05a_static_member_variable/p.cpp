#include <stdio.h>
#include <string.h>

#pragma GCC diagnostic ignored "-Wtautological-compare"


class Song
{
public:
	void print_pointers();

	// provide declaration of class variable "count_" here
	static int count_; // declare static member variable

private:
	char title_[20];
	int duration_;
};

// provide definition of class variable "count_" here
int Song::count_ = 0; // define and initialize static member variable, this is where the memory for the static member variable is allocated



void Song::print_pointers()
{
	// print addresses of count_, title_, and duration_
	printf("Address of count_: %p\n", (void*)&Song::count_); // print address of static member variable
	printf("Address of title_: %p\n", (void*)title_);
	printf("Address of duration_: %p\n", (void*)&duration_);
}


int main()
{
	Song s1, s2;			// create empty Song

	s1.print_pointers();
	s2.print_pointers();

	//output:
	//count_ prints the same address for s1 and s2, because it's one shared variable.
	//title_ and duration_ print different addresses for s1 and s2, because each object has its own.
	//count_ sits in a different address range from the other two. Static members live in the same area as global variables, not on the stack inside the object.
}
