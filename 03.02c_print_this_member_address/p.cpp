#include <stdio.h>

class Song
{
	char title[20];
	int duration;

public:
	void print_this_member_address()
	{
    printf("title:    %p\n", title);
    printf("this -> title: %p\n", this->title); // this->title is equivalent to title

	printf("duration: %p\n", &duration);
	printf("this -> duration: %p\n", &(this->duration)); // this->duration is equivalent to duration
	}
};

int main()
{
	Song s;

	s.print_this_member_address();

}
