#include <stdio.h>
#include <string.h>

class Song
{
public:
	Song() = default;
    
    Song(const Song&) = delete;              // delete the copy constructor
    Song& operator=(const Song&) = delete;    // delete copy-assignment

private:
	char title_[20];
	int duration_;
};


int main()
{
	Song s1;
	Song s2(s1);     // ERROR — this calls the copy constructor
	Song s3{s1};      // ERROR — same thing, different brackets
	Song s4 = s1;     // ERROR — this also calls the copy constructor (it's initialization, not assignment, despite the =)
}