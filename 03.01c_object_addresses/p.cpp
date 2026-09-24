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
	Song s1, s2, s3;

	printf("s1: %p\n", &s1); // print the address of s1
	printf("s2: %p\n", &s2);
	printf("s3: %p\n", &s3);

}
