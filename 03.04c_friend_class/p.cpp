#include <stdio.h>
#include <string.h>

class SongFriend;

class Song
{
	// provide code to make class SongFriend become a friend of class Song


public:
	void print()
	{
		printf("%s (%02d:%02d)\n", title_, duration_ / 60, duration_ % 60);
	}

private:
	char title_[20];
	int duration_;
};

class SongFriend
{
public:





};

int main()
{






}
