#include <stdio.h>
#include <string.h>

#pragma GCC diagnostic ignored "-Wtautological-compare"

class Song
{
public:
	void print() const
	{
		printf("%s (%02d:%02d)\n", title_, duration_/60, duration_%60);
	}

	void add_at_the_beginning(const char*, int);
	
	// declare static member function "print_all()"


	// provide declaration of class variables 
	// "pFirst_" and "pLast_"



private:

	char title_[20];
	int duration_;
	Song *pNext_;
	Song *pPrevious_;
};

// provide code to allocate memory for static class
// variables pFirst_ and pLast_ of class Song and
// initialize the variables with NULL




// provide definition of static member function "print_all()" of
// class Song that prints all available songs by calling method
// print() on each available song.







// provide the implementation of member function "add_at_the_beginning()"
// that stores the provided parameters title and duration to the allocated
// song, verifying that the length of title_ is not exceeded. Afterwards,
// the song is added at the beginning of the list




























int main()
{



	Song s1, s2, s3;			// create empty Song

	s1.add_at_the_beginning("Song1", 100);
	s2.add_at_the_beginning("Song2", 200);
	s3.add_at_the_beginning("Song3", 300);

	Song::print_all();
}
