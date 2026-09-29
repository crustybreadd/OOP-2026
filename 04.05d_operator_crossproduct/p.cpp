#include <stdio.h>

struct Vector
{
	double x_;
	double y_;
	double z_;
};

// provide code for operator * to implement the cross product
// cross product formula: (a1, a2, a3) x (b1, b2, b3) = (a2*b3 - a3*b2, a3*b1 - a1*b3, a1*b2 - a2*b1)
Vector operator*(const Vector& left, const Vector& right)
{
	printf("Calling operator*() for cross product\n");
	Vector result;
	result.x_ = left.y_ * right.z_ - left.z_ * right.y_;
	result.y_ = left.z_ * right.x_ - left.x_ * right.z_;
	result.z_ = left.x_ * right.y_ - left.y_ * right.x_;
	return result;
}







int main() {
	Vector a{1, 2, 3};
	Vector b{4, 5, 6};

	Vector c = a * b;

	printf("c.x_: %.2lf\n", c.x_);
	printf("c.y_: %.2lf\n", c.y_);
	printf("c.z_: %.2lf\n", c.z_);
}
