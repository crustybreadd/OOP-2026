#include <stdio.h>
#include <string.h>

class Song
{
public:
	char title_[20];
	int duration_;

	// provide parameterized constructor










	void print()
	{
		printf("%s (%02d:%02d)\n", title_, duration_ / 60, duration_ % 60);
	}
};


int main()
{
	Song s1("Song1", 123);
	Song s2("Song2");
}