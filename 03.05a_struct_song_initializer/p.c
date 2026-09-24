#include <stdio.h>

typedef struct Song
{
	char title[20];
	int duration;
} Song;

void print_song(Song *p)
{
	printf("%s (%02d:%02d)\n", p->title, p->duration/60, p->duration%60);
}

int main()
{
	// provide declaration and initialization here



	print_song(&s1);
	print_song(&s2);
}