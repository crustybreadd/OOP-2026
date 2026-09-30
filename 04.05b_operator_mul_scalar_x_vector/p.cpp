#include <stdio.h>

struct Vector
{
	double x_;
	double y_;
};

// provide code of operator * to calculate
// scalar * vector or vector * scalar
Vector operator*(double scalar, const Vector& v)
{
	printf("Calling operator*() for scalar * vector\n");
	return Vector{scalar * v.x_, scalar * v.y_};
}

Vector operator*(const Vector& v, double scalar)
{
	printf("Calling operator*() for vector * scalar\n");
	return Vector{scalar * v.x_, scalar * v.y_};
}



int main() {
	Vector a{2, 3};

	Vector b = 3 * a;
	Vector c = a * 3;

	printf("b.x_: %.2lf\n", b.x_);
	printf("b.y_: %.2lf\n", b.y_);
	printf("\n");
	printf("c.x_: %.2lf\n", c.x_);
	printf("c.y_: %.2lf\n", c.y_);
}
