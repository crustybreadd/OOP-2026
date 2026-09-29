#include <stdio.h>
#include <string.h>

class Song
{
	char title_[20];
	int duration_;

public:

	// provide constructor here












	void print()
	{
		printf("%s (%02d:%02d)\n", title_, duration_ / 60, duration_ % 60);
	}
};

int main()
{
	Song s1("Song1", 123);
	Song s2("123456789012345678901234567890", 234);	// overlong title

	s1.print();
	s2.print();
}