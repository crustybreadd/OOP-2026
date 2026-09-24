//song.cpp
#include <stdio.h>
#include "song.hpp"

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














