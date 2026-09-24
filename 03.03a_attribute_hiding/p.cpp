#include <stdio.h>

class Song
{
public: 
	void attribute_hiding(int duration) // the parameter duration hides the member variable duration
	{
		printf("&duration:         %p\n", &duration); // the parameter duration
		printf("&(this->duration): %p\n", &(this->duration) ); // this->duration is equivalent to duration in object s
	}

private:
	char title[20];
	int duration;
};

int main()
{
	Song s;

	s.attribute_hiding(30); // here the parameter duration is 30, but the member variable duration is uninitialized, so its value is indeterminate
}
