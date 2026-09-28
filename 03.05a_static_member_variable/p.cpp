#include <stdio.h>
#include <string.h>

#pragma GCC diagnostic ignored "-Wtautological-compare"


class Song
{
public:
	void print_pointers();

	// provide declaration of class variable "count_" here


private:
	char title_[20];
	int duration_;
};

// provide definition of class variable "count_" here




void Song::print_pointers()
{
	// print addresses of count_, title_, and duration_



}


int main()
{
	Song s1, s2;			// create empty Song

	s1.print_pointers();
	s2.print_pointers();
}
