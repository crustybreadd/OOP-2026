#include <stdio.h>
#include <string.h>

class Song
{
public:
	Song() = delete;

private:
	char title_[20];
	int duration_;
};


int main()
{
	Song s;	// error
}