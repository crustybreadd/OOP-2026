#include <stdio.h>
#include <string.h>

class Song
{
public:

























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
	Song s1;

	s1.set_title("Song123");
	s1.set_duration(123);
	
	s1.print();
}