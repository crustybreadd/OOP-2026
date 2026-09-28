#include <stdio.h>
#include <string.h>

class Song
{
	char title_[20];
	int duration_;

public:

	// provide constructor here
	Song(const char *title, int duration) // constructor to initialize title and duration
	{
		// print a message indicating that the constructor is being called
		printf("Calling constructor(%s, %d)\n", title, duration);

		strncpy(title_, title, sizeof(title_) - 1);
		title_[sizeof(title_) - 1] = '\0'; // ensure null-termination

		// ensure duration is non-negative
		duration_ = duration < 0 ? 0 : duration;
		// check if duration < 0 is true, if so, set duration_ to 0, otherwise keep the original duration value
		// : means "else" in this context, 
		// so if the condition is false, duration_ will be set to the original duration value which is the right of :
		// else if its true, duration_ will be set to 0 which is the left of :
	}


	void print()
	{
		printf("%s (%02d:%02d)\n", title_, duration_ / 60, duration_ % 60);
	}
};

int main()
{
	//constructors are called when objects are created
	Song s1("Song1", 123);
	Song s2("123456789012345678901234567890", -234);	// overlong title

	s1.print();
	s2.print();
}