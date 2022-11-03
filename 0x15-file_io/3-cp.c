#include "main.h"
/**
 * main - copy a file.
 * @argc: the number of args
 * @argv: the Args.
  * Return: 0
 */
int main(int argc, char *argv[])
{
	int sfd, dfd;
	int _read, sclose, dclose;
	char buff[1024];

	if (argc > 3 || argc < 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	sfd = open(*(argv + 1), O_RDONLY);
	if (sfd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", *(argv + 1));
		exit(98);
	}
	dfd = open(*(argv + 2), O_TRUNC | O_CREAT | O_WRONLY, 0664);
	while ((_read = read(sfd, buff, 1024)) > 0)
	{
		if (dfd == -1 || (write(dfd, buff, _read) != _read))
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", *(argv + 2));
			exit(99);
		}
	}
	if (_read < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", *(argv + 1));
		exit(98);
	}
	sclose = close(sfd);
	if (sclose < 0)
		dprintf(STDERR_FILENO, "Error: Can't close fd %i\n", sfd), exit(100);
	dclose = close(dfd);
	if (dclose < 0)
		dprintf(STDERR_FILENO, "Error: Can't close fd %i\n", dfd), exit(100);
	return (0);
}
