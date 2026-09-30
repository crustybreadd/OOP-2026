#include <stdio.h>
#include <string.h>

class Song
{
public:

	// constructor
	Song(const char* title, int duration)
	: title_{}, duration_{duration}
	{
		strncpy(title_, title, sizeof(title_) - 1);
		title_[sizeof(title_) - 1] = '\0';
	}

	// destructor => deletes the s1, s2's value that was decalred in the main
	/* The class name with a ~ (tilde) in front, no parameters, no return type
	not even void. This is how C++ recognizes it specifically as the destructor.*/
	~Song()
	{
    	printf("Calling destructor\n");
    	strncpy(title_, "xxxxxxxxxxxxxxxxxxx", sizeof(title_) - 1); // overwrite title with 19 'x's
    	duration_ = 0; // sets duration to 0
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
	// object s1, s2 created here
	Song s1("Song1", 123);
	Song s2("Song2", 234);

	s1.print();					// print "Title (min:sec)"
	s2.print();					// print "Title (min:sec)"
} // <- s1, s2's destructor fires HERE, automatically, as main() ends