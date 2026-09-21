#include <stdio.h>

class Song
{
public:
	void attribute_hiding(int duration)
	{
		printf("&duration:  %p\n", &duration);
		printf("&duration_: %p\n", &duration_);
	}

private:
	char title_[20];
	int duration_;
};

int main()
{
	Song s;

	s.attribute_hiding(30);
}
