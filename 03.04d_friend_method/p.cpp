#include <stdio.h>
#include <string.h>

class Song;


class SongFriend
{
public:
	void set_data(Song *pSong);
};


class Song
{
	// provide code to make method set_data of class 
	// SongFriend become a friend of class Song


public:
	void print()
	{
		printf("%s (%02d:%02d)\n", title_, duration_ / 60, duration_ % 60);
	}

private:
	char title_[20];
	int duration_;
};








int main()
{
	Song s;					// create empty Song
	SongFriend sf;			// create empty SongFriend

	sf.set_data(&s);		// set Song data via SongFriend

	s.print();				// check if Song has changed
}
