#include <stdio.h>

struct Vector
{
	double x_;
	double y_;
};

// instead of Vector, use bool as the return type for operator== to compare two Vector objects
// because operator== is a comparison operator, it should return a boolean value indicating whether the two Vector objects are equal or not
bool operator==(const Vector& left, const Vector& right)
{
	printf("Calling operator==()\n");
	return left.x_ == right.x_ && left.y_ == right.y_;
}





int main() {
	Vector a{1, 2};
	Vector b{3, 4};

	printf("a == a: %d\n", a == a);
	printf("a == b: %d\n", a == b);
}
