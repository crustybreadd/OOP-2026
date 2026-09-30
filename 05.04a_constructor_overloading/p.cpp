#include <stdio.h>
#include <string.h>

class Song
{
public:
	char title_[20];
	int duration_;

	// provide parameterized constructor
	// no need for void as there is no return type for constructors
	Song(const char* title, int duration)
	{
		strncpy(title_, title, sizeof(title_) - 1);
		title_[sizeof(title_) - 1] = '\0'; // ensure null-termination
		duration_ = (duration < 0) ? 0 : duration;
		printf("Calling constructor (%s , %d)\n", title_ , duration_ );
	}



	// provide default constructor
	Song()
	{
		strcpy(title_, "Unknown");
		duration_ = 0;
		printf("Calling default constructor (%s , %d)\n", title_ , duration_);
	}



	void print()
	{
		printf("%s (%02d:%02d)\n", title_, duration_ / 60, duration_ % 60);
	}
};


int main()
{
	Song s1("Song1", 123); // calls the parameterized one
	Song s2; // calls the default one
}