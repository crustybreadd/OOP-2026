#include <stdio.h>
#include <string.h>


class Song
{
	// provide code to make method main become a friend


public:
	void print()
	{
		printf("%s (%02d:%02d)\n", title_, duration_ / 60, duration_ % 60);
	}

private:
	char title_[20];
	int duration_;
};


int main()
{
	Song s;					// create empty Song



	
	s.print();				// check if Song has changed
}
