#include <stdio.h>

/**
  * main - Prints all the arguments it receives one per line
  * @argc: argument count
  * @argv: array of arguments
  *
  * Return: Always 0
  */

int main(int argc, char **argv)
{
	int i = 0;

	while (i < argc)
	{
		printf("%s\n", *(argv + i));
		i++;
	}
	return (0);
}
