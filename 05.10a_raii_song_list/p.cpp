#include <stdio.h>
#include <string.h>

class SongLE	// LE = List Entry
{
public:

	SongLE(const char* title = "", int duration = 0);
	~SongLE();

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




SongLE::SongLE(const char* title, int duration)
: duration_{duration}
{












}


SongLE::~SongLE()
{













}

// provide method print()







// provide static method print_list()











int main()
{





}
