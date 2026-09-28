#include <stdio.h>
#include <string.h>

class Song;


class SongFriend
{
public:
	void set_data(Song *pSong); // address of Song object is passed to this method
};


class Song
{
	// provide code to make method set_data of class 
	// SongFriend become a friend of class Song
	friend void SongFriend::set_data(Song *pSong); // declare set_data as a friend function of Song


public:
	void print()
	{
		printf("%s (%02d:%02d)\n", title_, duration_ / 60, duration_ % 60);
	}

private:
	char title_[20];
	int duration_;
};

//placed here as if it were to be above the class Song definition,
//it would not compile because the compiler would not know what Song is yet.
void SongFriend::set_data(Song *pSong) // define set_data method of class SongFriend
{
	strcpy(pSong->title_, "My Song");
	pSong->duration_ = 210;
}



int main()
{
	Song s;					// create empty Song
	SongFriend sf;			// create empty SongFriend

	sf.set_data(&s);		// set Song data via SongFriend

	s.print();				// check if Song has changed
}
