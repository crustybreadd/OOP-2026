#include <stdio.h>
#include <string.h>

class Song
{
	char title[20];
	int duration;

public:
	void print()
	{
		printf("%s (%02d:%02d)\n", title, duration / 60, duration % 60);
	}

	void init_by_attribute()
	{


	}

	void init_by_this_attribute()
	{


	}
};

int main()
{
	Song s;

	s.init_by_attribute();
	s.print();

	s.init_by_this_attribute();
	s.print();
}
