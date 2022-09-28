#include "main.h"

/**
 * _put recursion - prints a string
 * @s:pointer block of memmory to fill
 * Return:void
 */
void _puts_recursion(char *s)
{
	if (*s == '\0')
	{
		_putchar('\n');
		return;
	}
	_putchar(*s);

	_puts_recursion(s + 1);
}
