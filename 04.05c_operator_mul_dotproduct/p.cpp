#include <stdio.h>

struct Vector
{
	double x_;
	double y_;
};

// provide code for operator * to calculate the dotproduct





int main() {
	Vector a{1, 2};
	Vector b{3, 4};

	int c = a * b;

	printf("c: %d\n", c);
}
