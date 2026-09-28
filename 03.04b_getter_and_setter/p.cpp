#include <stdio.h>
#include <string.h>

class Song
{
public:

	int duration() // getter method
	{
    return duration_;
	}

	char *title() // getter method
	{
		return title_;
	}

	void set_title(const char* title) // setter method
	{
		if (strlen(title) > sizeof(title_) - 1) // check if title is too long
		{
			strncpy(title_, title, sizeof(title_) - 1); //if string is too long, truncate it to 19 characters and add null terminator
			title_[sizeof(title_) - 1] = '\0'; // ensure null termination

			//printf("Title is too long!\n"); 
			//exit(1); // exit the program with an error code
		}
		else
		{
			strcpy(title_, title); // store the title as is
		}
	}

	void set_duration(int duration) // setter method 
	{
		if (duration < 0) // check if duration is negative
		{
			duration_ = -duration; // if negative number is entered, store as absolute value

<<<<<<< HEAD


















=======
			//printf("Duration is negative!\n");
			//exit(1); // exit the program with an error code
		}
		else
		{
			duration_ = duration; // store the duration as is
		}
	}
>>>>>>> bf27bcc (save my changes 2026 09 28)

	void print()
	{
		printf("%s (%02d:%02d)\n", title_, duration_ / 60, duration_ % 60);
	}

private:
	char title_[20];
	int duration_;
};


int main()
{
	Song s1 , s2;

	s1.set_title("Song12345678901234567890"); // title too long test
	s1.set_duration(-123); // negative duration test

	s2.set_title("Song2"); // valid title test
	s2.set_duration(123); // valid duration test
	
	s1.print();
	s2.print();
}