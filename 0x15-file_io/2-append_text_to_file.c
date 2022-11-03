#include "main.h"
/**
 * append_text_to_file - append
 * @filename: selected file
 * @text_content: the content to write
 * Return: 1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, out, i;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content)
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
