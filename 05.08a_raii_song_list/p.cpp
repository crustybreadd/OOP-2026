#include <stdio.h>
#include <string.h>


class SongLE;

SongLE *pFirst = nullptr, *pLast = nullptr;


class SongLE	// LE = List Entry
{
public:



































	SongLE(const SongLE&) = delete;				// avoid copying
	SongLE& operator=(const SongLE&) = delete;	// avoid copy-assignment

	void print()
	{
		printf("%s (%02d:%02d)\n", title_, duration_ / 60, duration_ % 60);
	}

	SongLE* pNext()
	{
		return pNext_;
	}

private:
	char title_[20];
	int duration_;

	SongLE *pNext_, *pPrevious_;
};

void print_list()
{






}
//<--print_list()


int main()
{





}
