#include <stdio.h>

struct Vector
{
	double x_;
	double y_;
};

Vector operator+(const Vector& left, const Vector& right)
{
	printf("Calling operator+()\n");
	return Vector{left.x_ + right.x_, left.y_ + right.y_};
}

int main() {
	Vector a{1, 2};
	Vector b{3, 4};

	Vector c = a + b;

	printf("c.x_: %.2lf\n", c.x_);
	printf("c.y_: %.2lf\n", c.y_);
}
