#include <stdio.h>
#include <string.h>

class Song
{
public:

	void add_at_the_beginning(const char*, int);
	void print();
	Song * pFirst() {return pFirst_;}
	Song* pNext() {return pNext_;}

private:
	char title_[20];
	int duration_;
	Song *pNext_;
	Song *pPrevious_;
	static Song *pFirst_;
	static Song *pLast_;
};

Song *Song::pFirst_ = NULL;
Song *Song::pLast_ = NULL;

void Song::add_at_the_beginning(const char *title, int duration)
{
	strncpy(title_, title, sizeof(title_) - 1);
	duration_ = duration;

	pPrevious_ = NULL;
	pNext_ = pFirst_ ? pFirst_ : NULL;
	pFirst_ = this;
	if(pLast_ == NULL) pLast_ = this;
}
void Song::print()
{
	printf("%s (%02d:%02d)\n", title_, duration_/60, duration_%60);

}

void print_all_songs(const Song & s)
{
	for(Song * p = s.pFirst(); p; p = p->pNext())
	{
		p->print();
	}
}


int main()
{
	Song s1, s2, s3;

	s1.add_at_the_beginning("Song1", 100);
	s2.add_at_the_beginning("Song2", 200);
	s3.add_at_the_beginning("Song3", 300);
	
	print_all_songs(s1);
}