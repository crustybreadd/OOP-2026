#include <stdio.h>
#include <string.h>

class Song
{
public:
	Song()
	{
		printf("Calling Constructor Song\n");
	}

private:
	char title_[20];
	int duration_;
};


class Playlist
{
public:
	Playlist()
	{
		printf("Calling Constructor Playlist\n");
	}

private:
	Song s1, s2, s3;
};

int main()
{
	Playlist p;
}