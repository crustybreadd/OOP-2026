#include <stdio.h>

class Counter
{
public:
	// provide static member function count() that increments
	// "value_" before printing it, followed by a newline
	static void count()
	{
		value_++;				// increment static member variable value_
		printf("%d\n", value_); // then print the value of static member variable value_ followed by a newline
	}




private:
	// provide declaration static member variable value_ (integer)
	static int value_; // declare static member variable value_
};

// provide definition and initialization with 0 
// of static member variable value_
int Counter::value_ = 0; // define and initialize static member variable value_


int main()
{
	// provide code to call static member function 
	// "count" of class Counter three times
	Counter::count();
	Counter::count();
	Counter::count();

}
