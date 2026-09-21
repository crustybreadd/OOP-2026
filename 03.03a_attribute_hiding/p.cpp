#include <stdio.h>

class Song
{
public:
	void attribute_hiding(int duration)
	{
		printf("&duration:         %p\n", &duration);
		printf("&(this->duration): %p\n", &(this->duration) );
	}

private:
	char title[20];
	int duration;
};

int main()
{
	Song s;

	s.attribute_hiding(30);
}
