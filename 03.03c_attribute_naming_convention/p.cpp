#include <stdio.h>
#include <string.h>

class Song
{
public:

	char title_[20];
	int duration_;

	Song(const char* title, int duration)
	{
		// copy max. 19 chars
		strncpy(title_, title, sizeof(title_) - 1);
		title_[sizeof(title_) - 1] = '\0';

		duration_ = duration;
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

	s1.print();							// print "Name (min:sec)"
	s2.print();							// print "Name (min:sec)"
}