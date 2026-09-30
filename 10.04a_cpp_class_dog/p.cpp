#include <stdio.h>

class Dog
{
public:
	void bark()
	{
		printf("woof\n");
		printf("woof\n");
		printf("woof\n");
	}
};

int main()
{
	Dog d;
	d.bark();
}
