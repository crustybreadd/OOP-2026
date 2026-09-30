#include <stdio.h>
#include <string.h>

class Song
{
public:

	// constructor
	Song(const char* title, int duration)
	: title_{}, duration_{duration}
	{
		printf("Calling constructor(title, duration)\n");
		strncpy(title_, title, sizeof(title_) - 1);
		title_[sizeof(title_) - 1] = '\0';
	}

	// copy constructor
	Song(const Song& other) : duration_{other.duration_}
	{
		printf("Calling copy constructor\n");
		memcpy(title_, other.title_, sizeof title_);
	}


	// Syntax: the class name with a ~ in front, no parameters, no return type
	// A destructor is the opposite of a constructor: instead of running when an object is created,
	//it runs automatically when an object is destroyed
	~Song()
	{
		printf("Calling destructor\n");

		// overwriting variables on the stack
		// memset fills a block of memory with a repeated byte, same as strncpy
		//memset(title_, 'x', sizeof(title_) - 1);
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