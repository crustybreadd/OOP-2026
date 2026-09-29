#include <stdio.h>

struct Vector
{
	double x_;
	double y_;
};

// provide code for operator * to calculate the dotproduct
// dot product formula: (a1, a2) . (b1, b2) = a1*b1 + a2*b2
int operator*(const Vector& left, const Vector& right)
{
	printf("Calling operator*() for dotproduct\n");
	return left.x_ * right.x_ + left.y_ * right.y_;
}




int main() {
	Vector a{1, 2};
	Vector b{3, 4};

	int c = a * b;

	printf("c: %d\n", c);
}
