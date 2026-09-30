#include <stdio.h>
#include <string.h>

class Song
{
public:
	char title_[20];
	int duration_;

	// constructor
	// The colon : reads as: "before running anything in the body, initialize duration_ directly using the value duration."
	// duration_{duration} means narrowing is a compile error
	// duration_(duration) able to convert bigger value type like double into int
	Song (const char* title , int duration) : duration_{duration}
	{

		// but we cant do : duration_{duration}, title_{title}   // this does NOT do what you'd expect
		// title_ is a fixed-size array (char title_[20]), so title_ can only be assigned the normal way
		strncpy(title_ , title , sizeof(title_) - 1);
		title_[sizeof(title_) - 1] = '\0';

		//duration_ = (duration < 0) ? 0 : duration;

		//printf("%s (%02d:%02d)\n", title_, duration_ / 60, duration_ % 60);
	}



	void print()
	{
		printf("%s (%02d:%02d)\n", title_, duration_ / 60, duration_ % 60);
	}
};


int main()
{
	Song s1("Song1", 123);
	Song s2("Song2", 234);

	s1.print();
	s2.print();
}