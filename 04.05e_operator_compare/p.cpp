#include <stdio.h>

struct Vector
{
	double x_;
	double y_;
};







int main() {
	Vector a{1, 2};
	Vector b{3, 4};

	printf("a == a: %d\n", a == a);
	printf("a == b: %d\n", a == b);
}
