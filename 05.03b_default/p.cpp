#include <stdio.h>
#include <string.h>

class Song
{
public:
	/*Song(const char* title = "Unknown", int duration = 0)
	{
		strncpy(title_, title, sizeof(title_) - 1);
		title_[sizeof(title_) - 1] = '\0'; // Ensure null-termination
		duration_ = duration;
	}*/

	// set default constructor
	Song() = default; // "bring back the automatic default constructor, please"

	void print() const
	{
		printf("Title: %s, Duration: %d seconds\n", title_, duration_);
	}

private:
	char title_[20];
	int duration_;
};


int main()
{
	Song s1;
	s1.print();
}