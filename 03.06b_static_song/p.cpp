#include <stdio.h>
#include <string.h>

#pragma GCC diagnostic ignored "-Wtautological-compare"

class Song
{
public:
	void print() const
	{
		// prints the title and duration of the song in the format "title (mm:ss)"
		printf("%s (%02d:%02d)\n", title_, duration_/60, duration_%60);
	}

	// constructor that initializes the title and duration of the song
	void add_at_the_beginning(const char*, int);
	
	// declare static member function "print_all()"
	static void print_all();

	// provide declaration of class variables 
	// "pFirst_" and "pNext_"
	static Song *pFirst_; // one shared "start of list" pointer
	static Song *pLast_; // one shared "end of list" pointer


private:

	char title_[20];
	int duration_;
	Song *pNext_;
	Song *pPrevious_;
};

// provide code to allocate memory for static class
// variables pFirst_ and pLast_ of class Song and
// initialize the variables with the C++ null pointer
Song *Song::pFirst_ = NULL; // allocate memory for static class variable pFirst_ and initialize it with the C++ null pointer
Song *Song::pLast_ = NULL; // allocate memory for static class variable pLast_ and initialize it with the C++ null pointer



// provide definition of static member function "print_all()" of
// class Song that prints all available songs by calling method
// print() on each available song.
void Song::print_all()
{
	Song *pCurrent = pFirst_; // start from the first song
	while (pCurrent != NULL) // while there are more songs
	{
		pCurrent->print(); // print the current song
		pCurrent = pCurrent->pNext_; // move to the next song

	}

	// alternative implementation using a for loop

	/*for (Song *pCurrent = pFirst_; pCurrent != NULL; pCurrent = pCurrent->pNext_)
	{
		p->print(); // print the current song
	}*/
}






// provide the implementation of member function "add_at_the_beginning()"
// that stores the provided parameters title and duration to the allocated
// song, verifying that the length of title_ is not exceeded. Afterwards,
// the song is added at the beginning of the list
void Song::add_at_the_beginning(const char* title, int duration)
{
	// check if the length of title is not exceeded
	if (strlen(title) >= sizeof(title_))
	{
		printf("Title is too long!\n");
		return;
	}

	// store the provided parameters title and duration to the allocated song
	strcpy(title_, title);
	duration_ = duration;

	// add the song at the beginning of the list
	pNext_ = pFirst_; // set the next pointer of the new song to the current first song
	pPrevious_ = NULL; // set the previous pointer of the new song to NULL

	if (pFirst_ != NULL) // if there is a first song
	{
		// "this" is from the current object, which is the new song being added
		// pFirst_ still points to s3 at this moment (hasn't been updated yet)
		// so this line means: s3->pPrevious_ = s4;
		// in plain words: "s3, your previous song is now s4"
		pFirst_->pPrevious_ = this; 
	}
	else // if there is no first song
	{
		pLast_ = this; // set the last pointer to the new song
	}

	pFirst_ = this; // set the first pointer to the new song

	if (pLast_ == NULL) // if there is no last song
	{
		pLast_ = this; // set the last pointer to the new song
	}

}




int main()
{



	Song s1, s2, s3;			// create empty Song

	s1.add_at_the_beginning("Song1", 100);
	s2.add_at_the_beginning("Song2", 200);
	s3.add_at_the_beginning("Song3", 300);

	// this replaces s1/s2/s3.print_all(); with Song::print_all(); to call the static member function
	Song::print_all(); 
}
