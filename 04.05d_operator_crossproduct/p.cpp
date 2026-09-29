#include <stdio.h>

struct Vector
{
	double x_;
	double y_;
	double z_;
};

// provide code for operator * to implement the cross product








int main() {
	Vector a{1, 2, 3};
	Vector b{4, 5, 6};

	Vector c = a * b;

	printf("c.x_: %.2lf\n", c.x_);
	printf("c.y_: %.2lf\n", c.y_);
	printf("c.z_: %.2lf\n", c.z_);
}
