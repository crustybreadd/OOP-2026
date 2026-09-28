#include <stdio.h>
#include <string.h>

class SongFriend;

class Song
{
	// provide code to make class SongFriend become a friend of class Song
	friend class SongFriend;

public:
	void print()
	{
		printf("%s (%02d:%02d)\n", title_, duration_ / 60, duration_ % 60);
	}

private:
	char title_[20];
	int duration_;
};

class SongFriend // friend class of Song
{
public:
	void set_data(Song *pSong) // address of Song object is passed to this method
	{
		strcpy(pSong->title_, "SongFriend"); // set title to "SongFriend"
		pSong->duration_ = 123; // set duration to 123 seconds
	}

};

int main()
{

	Song s;
	SongFriend sf; // create an object of SongFriend class

	sf.set_data(&s); // sends the address of Song object s to set_data method of SongFriend class
	s.print(); // print the data of Song object s

}
