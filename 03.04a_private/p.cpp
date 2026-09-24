#include <stdio.h>

class Song
{
public:
	void print()
	{
		printf("%s (%02d:%02d)\n", title_, duration_ / 60, duration_ % 60);
	}

	void enter()
	{
		printf("Title: ");
		scanf("%s", title_);
		printf("Duration: ");
		scanf("%d", &duration_);
	}

private:
	char title_[20];
	int duration_;
};

int main()
{
	Song s;

	s.enter();
	s.print();


}
