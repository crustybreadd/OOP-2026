#include <stdio.h>
#include <string.h>

struct Vector
{
	// Provide code to implement += here
	// use inline because it is a small function and we want to avoid the overhead of a function call
	inline Vector& operator+=(const Vector& other)
	{
		printf("Calling operator+=()\n");
		// Add the x and y components of the other vector to this vector
		// this points to the current object, so we can use it to access the x_ and y_ members of the current object
		this->x_ += other.x_;
		this->y_ += other.y_;

		// use * to dereference the pointer and return a reference to the current object
		return *this; 
	}



	
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
