#include "main.h"
/**
 * read_textfile - read
 * @filename: selected file
 * @letters: amount to read
 * Return: size
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd, in, out;
	char *buff;

	if (filename == NULL)
		return (0);

	buff = malloc(sizeof(char) * letters);
	if (buff == NULL)
		return (0);

	fd = open(filename, O_RDONLY, 600);
	if (fd == -1)
	{
		free(buff);
		return (0);
	}
	in = read(fd, buff, letters);
	if (in == -1)
	{
		free(buff);
		return (0);
	}

	out = write(STDOUT_FILENO, buff, in);
	if (out == -1 || out != in)
	{
		return (0);
	}

	free(buff);
	close(fd);
	return (out);
}
