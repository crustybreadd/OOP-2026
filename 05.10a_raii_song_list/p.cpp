#include <stdio.h>
#include <string.h>

class SongLE	// LE = List Entry
{
public:

	SongLE(const char* title = "", int duration = 0);
	~SongLE(); // ~ means destructor which will remove the song from the list

	SongLE(const SongLE&) = delete;				// avoid copying
	SongLE& operator=(const SongLE&) = delete;	// avoid copy-assignment

	void print();
	static void print_list();

private:
	char title_[20];
	int duration_;

	SongLE *pNext_, *pPrevious_;
	static SongLE *pFirst_, *pLast_;
};


// provide pointers pFirst and pLast
SongLE *SongLE::pFirst_ = nullptr; // no song in the list yet
SongLE *SongLE::pLast_ = nullptr; // no song in the list yet


//construsctor that appends the song to the end of the list
SongLE::SongLE(const char* title, int duration)
: duration_{duration}
{
	
	strncpy(title_, title, sizeof(title_) - 1);
	title_[sizeof(title_) - 1] = '\0'; // Ensure null-termination

	// add this song to the list
	if (pFirst_ == nullptr) // if the list is empty
	{
		pFirst_ = this; // this song is the first song in the list
		pLast_ = this; // this song is also the last song in the list
		pNext_ = nullptr; // no next song
		pPrevious_ = nullptr; // no previous song
	}
	else // if the list is not empty
	{
		pLast_->pNext_ = this; // add this song to the end of the list
		pPrevious_ = pLast_; // this song's previous song is the last song in the list
		pNext_ = nullptr; // no next song
		pLast_ = this; // this song is now the last song in the list
	}



}


// provide destructor that removes the song from the list
SongLE::~SongLE()
{
	// remove this song from the list
	if (pPrevious_)
	{
		pPrevious_->pNext_ = pNext_;
	}
	else
	{
		pFirst_ = pNext_;
	}

	if (pNext_)
	{
		pNext_->pPrevious_ = pPrevious_;
	}
	else
	{
		pLast_ = pPrevious_;
	}
}


// provide method print()
void SongLE::print()
{
	printf("Title: %s, Duration: %d seconds\n", title_, duration_);
}


// provide static method print_list()
void SongLE::print_list()
{
	SongLE *pCurrent = pFirst_;
	while (pCurrent)
	{
		pCurrent->print();
		pCurrent = pCurrent->pNext_;
	}
}


int main()
{
	
	SongLE s1("Song 1", 180);
	SongLE s2("Song 2", 200);
	SongLE s3("Song 3", 240);

	printf("Current song list:\n");
	SongLE::print_list();

	// remove s2 from the list
	{
		SongLE s4("Song 4", 300);
		printf("\nCurrent song list after adding Song 4:\n");
		SongLE::print_list();
	} // s4 goes out of scope and is destroyed here

	printf("\nCurrent song list after removing Song 4:\n");
	SongLE::print_list();


}
