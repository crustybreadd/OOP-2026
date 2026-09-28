#include <stdio.h>

class Song
{
	char title_[20];
	int duration_;

public:

	// provide default constructor here
	Song()   // <- no parameters at all = default constructor
    {
        title_[0] = '\0';   // empty string
        duration_ = 0;

        printf("Calling default constructor\n");
    }


	void print()
	{
		printf("%s (%02d:%02d)\n", title_, duration_ / 60, duration_ % 60);
	}
};


int main()
{
	Song s1;
	s1.print();
}