#include <stdio.h>
#include <string.h>

class Song
{
public:
	Song(const char* title, int duration)
	: title_{}, duration_{duration}
	{
		strncpy(title_, title, sizeof(title_) - 1);
		title_[sizeof(title_) - 1] = '\0';
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
	Song s2("Song2", 234);

	s1.print();					// print "Title (min:sec)"
	s2.print();					// print "Title (min:sec)"
}