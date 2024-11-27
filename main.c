#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    _printf("Length: _printf=[%d], printf=[%d]\n", len, len2);

    len = _printf("Character:[%c]\n", 0);
    len2 = printf("Character:[%c]\n", 0);
    _printf("Length: _printf=[%d], printf=[%d]\n", len, len2);

    len = _printf("Character:[%c]\n", 'H');
    len2 = printf("Character:[%c]\n", 'H');
    _printf("Length: _printf=[%d], printf=[%d]\n", len, len2);

    len = _printf("String:[%s]\n", NULL);
    len2 = printf("String:[%s]\n", NULL);
    _printf("Length: _printf=[%d], printf=[%d]\n", len, len2);

    len = _printf("String:[%s]\n", "I am a string!");
    len2 = printf("String:[%s]\n", "I am a string!");
    _printf("Length: _printf=[%d], printf=[%d]\n", len, len2);

    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Length: _printf=[%d], printf=[%d]\n", len, len2);

    len = _printf("Negative:[%d]\n", -762534);
    len2 = printf("Negative:[%d]\n", -762534);
    _printf("Length: _printf=[%d], printf=[%d]\n", len, len2);

    len = _printf("Integer MAX:[%d]\n", INT_MAX);
    len2 = printf("Integer MAX:[%d]\n", INT_MAX);
    _printf("Length: _printf=[%d], printf=[%d]\n", len, len2);

    len = _printf("Integer MIN:[%d]\n", INT_MIN);
    len2 = printf("Integer MIN:[%d]\n", INT_MIN);
    _printf("Length: _printf=[%d], printf=[%d]\n", len, len2);

    ui = (unsigned int)INT_MAX + 1024;
    len = _printf("Unsigned:[%u]\n", ui);
    len2 = printf("Unsigned:[%u]\n", ui);
    _printf("Length: _printf=[%d], printf=[%d]\n", len, len2);

    addr = (void *)0x7ffe637541f0;
    len = _printf("Address:[%p]\n", addr);
    len2 = printf("Address:[%p]\n", addr);
    _printf("Length: _printf=[%d], printf=[%d]\n", len, len2);

    addr = NULL;
    len = _printf("Address:[%p]\n", addr);
    len2 = printf("Address:[%p]\n", addr);
    _printf("Length: _printf=[%d], printf=[%d]\n", len, len2);

    /* Test multiple specifiers in one call
    len = _printf("Char: %c, String: %s, Percent: %%, Int: %d, Unsigned: %u, Addr: %p\n", 'A', "Test", -123, 123U, addr);
    len2 = printf("Char: %c, String: %s, Percent: %%, Int: %d, Unsigned: %u, Addr: %p\n", 'A', "Test", -123, 123U, addr);
    _printf("Length: _printf=[%d], printf=[%d]\n", len, len2); */

	len2 = _printf("%");
	len = printf("%");
	printf ("%d\n", len);
	_printf ("%d\n", len2);

	/*len = _printf("Reverse: %r\n", "Reverse");
	printf ("Length: _printf=[%d]", len);*/

	len = _printf("rot13: %R\n", "");
	printf ("Length: _printf=[%d]", len);

    return (0);
}
