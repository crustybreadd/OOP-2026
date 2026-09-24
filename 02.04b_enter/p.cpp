#include <stdio.h>

class Song
{
	char title[20];
	int duration;

public:
	void print()
	{
		printf("%s (%02d:%02d)\n", title, duration / 60, duration % 60);
	}

	// provide method "enter" here
	void enter()
	{
		printf("Title: ");
		scanf("%s", title);		// key in name

		printf("Duration: ");
		scanf("%d", &duration);	// key in duration
	}

};

int main()
{
	Song s;

	//printf("Title: ");
	//scanf("%s", s.title);		// key in name

	//printf("Duration: ");
	//scanf("%d", &s.duration);	// key in duration

	s.enter(); //Goes into the enter() function through class Song 
	s.print(); //Goes into the print() function through class Song
}
