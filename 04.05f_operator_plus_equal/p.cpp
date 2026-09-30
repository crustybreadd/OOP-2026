#include <stdio.h>
#include <string.h>

struct Vector
{
	// Provide code to implement += here






	
	double x_;
	double y_;
};

int main() {
	Vector a{1, 2};
	Vector b{3, 4};

	a += b;

	printf("a.x_: %.2lf\n", a.x_);
	printf("a.y_: %.2lf\n", a.y_);
}
