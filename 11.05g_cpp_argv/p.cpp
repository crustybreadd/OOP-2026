#include <stdio.h>


int main(int argc, char *argv[])
{
	for(int i = 0; argv[i]; i++)
	{
		printf("argv[%i]: %p  => %s\n", i, argv[i], argv[i]);
	}
}