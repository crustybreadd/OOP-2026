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
	// inline static member variables are allowed in C++17 and later, so we can define it here in the class definition.
	// so instead of defining it outside the class, we can define it here as inline static.
	// this means that the variable is shared among all instances of the class, and it has internal linkage, so it can be defined in a header file without violating the one definition rule.
	static inline int count_; // declare static member variable


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
