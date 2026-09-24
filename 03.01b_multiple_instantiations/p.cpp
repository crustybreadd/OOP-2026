#include <stdio.h>

class Song
{
	char title[20];
	int duration;

public:
	void print()
	{
		printf("%s (%02d:%02d)\n", title, duration / 60, duration % 60);
	}

	void enter()
	{
		printf("Title: ");
		scanf("%s", title);		// key in name

		printf("Duration: ");
		scanf("%d", &duration);	// key in duration
	}
};

int main()
{
	
Song s1, s2, s3; // create three Song objects

    s1.enter(); // key in data for s1
    s2.enter();
    s3.enter();
    printf("\n");

    s1.print(); // print data for s1
    s2.print();
    s3.print();


}
