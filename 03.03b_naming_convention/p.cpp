#include <stdio.h>

class Song
{
public:
	void attribute_hiding(int duration)
	{
		printf("&duration:  %p\n", &duration); // the parameter duration
		printf("&duration_: %p\n", &duration_); // the member variable duration_ is hidden by the parameter duration
	}

private:
	char title_[20];
	int duration_; // member variable duration_ is hidden by the parameter duration
};

int main()
{
	Song s;

	s.attribute_hiding(30);
}
