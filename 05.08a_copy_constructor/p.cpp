#include <stdio.h>
#include <string.h>

class Song
{
public:
	Song(const char* title, int duration)
	: title_{}, duration_{duration}
	{
		printf("Calling constructor(title, duration)\n");
		strncpy(title_, title, sizeof(title_) - 1);
		title_[sizeof(title_) - 1] = '\0';
	}

	// provide copy constructor here






	~Song()
	{
		printf("Calling destructor\n");

		// overwriting variables on the stack
		strncpy(title_, "xxxxxxxxxxxxxxxxxxx", sizeof(title_) - 1);
		duration_ = 0;
	}

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
	Song s1("Song1", 123);
	
	Song s2(s1);				// copy constructor
	Song s3 {s1};				// copy constructor
	Song s4 = s1;				// initialization


	s1.print();
	s2.print();
	s3.print();
	s4.print();
}
