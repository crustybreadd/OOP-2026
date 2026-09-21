#include <stdio.h>

class Song
{
	char title[20];
	int duration;

public:
	void print_this_member_address()
	{




	}
};

int main()
{
	Song s;

	s.print_this_member_address();
}
