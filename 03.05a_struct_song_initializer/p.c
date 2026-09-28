#include <stdio.h>

typedef struct Song 
{
	char title[20]; 
	int duration;
} Song; // thanks to typedef — no "struct" keyword needed

void print_song(Song *p)
{
	printf("%s (%02d:%02d)\n", p->title, p->duration/60, p->duration%60);
}

int main()
{	
	// provide declaration and initialization here
	// thanks to typedef — no "struct" keyword needed
	//struct initializer list
	Song s1 = {"My Song", 210}; // declare and initialize a Song object with title "My Song" and duration 210 seconds
	Song s2 = {"123456789012345678901234567890", 180}; // error: title exceeds 20 characters, but will be truncated to fit

	print_song(&s1);
	print_song(&s2);
}