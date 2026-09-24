#include <stdio.h>

class Song
{
	char title[20];
	int duration;

public:
	// provide declaration of methods print() and enter()
	void print();
	void enter();

};

// provide definition of class Song method print()
void Song::print()
{
	printf("%s (%02d:%02d)\n", title, duration / 60, duration % 60);
}

// provide definition of class Song method enter()
void Song::enter()
{
	printf("Title: ");
	scanf("%s", title);
	printf("Duration: ");
	scanf("%d", &duration);
}


int main()
{
	Song s;

	s.enter();
	s.print();
}
