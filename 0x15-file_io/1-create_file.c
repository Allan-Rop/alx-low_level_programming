#include "main.h"
/**
 * create_file - write
 * @filename: selected file
 * @text_content: the content to write
 * Return: 1
 */
int create_file(const char *filename, char *text_content)
{
	int fd, out, i;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[i])
			i++;

		out = write(fd, text_content, i);
		if (out == -1)
			return (-1);
	}
	close(fd);
	return (1);
}
