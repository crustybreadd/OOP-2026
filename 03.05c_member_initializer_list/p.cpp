#include <stdio.h>
#include <string.h>

class Song
{
public:
	char title_[20];
	int duration_;

	// constructor
	// duration_ is initialized using a member initializer list,
	//which is more efficient than assigning it in the constructor body
	Song(const char *title, int duration) : duration_(duration < 0 ? 0 : duration)
	{
		// title cannot be initialized in the member initializer list because it is an array,
		//so we use strncpy to copy the title into title_
		strncpy(title_, title, sizeof(title_) - 1);
		title_[sizeof(title_) - 1] = '\0'; // ensure null-termination
	}





	void print()
	{
		printf("%s (%02d:%02d)\n", title_, duration_ / 60, duration_ % 60);
	}
};


int main()
{
	Song s1("Song1", 123);
	Song s2("Song233333333333333333333333333333333333333333", -234);

	s1.print();
	s2.print();
}