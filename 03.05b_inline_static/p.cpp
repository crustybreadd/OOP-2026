#include <stdio.h>
#include <string.h>

#pragma GCC diagnostic ignored "-Wtautological-compare"

#if __cplusplus < 201703L
#error "This code has to be compiled with C++17 or later!"
#error "Use g++ -o p -std=c++17 p.cpp"
#endif


class Song
{
public:
	void print_pointers();

	// provide declaration and definition of class variable "count_" here


private:
	char title_[20];
	int duration_;
};


void Song::print_pointers()
{
	// print addresses of count_, title_, and duration_
	printf("count_:    %p\n", &count_);
	printf("title_:    %p\n", title_);
	printf("duration_: %p\n\n", &duration_);
}


int main()
{
	Song s1, s2;			// create empty Song

	s1.print_pointers();
	s2.print_pointers();
}
