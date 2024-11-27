#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct print - Struct for specifiers and functions
 * @specifier: The specifier character
 * @f: The function pointer
 */

typedef struct print
{
	char *specifier;
	int (*f)(va_list);
} print_t;

void _putchar(char c);
int _printf(const char *format, ...);
int asset_print_char(va_list args);
int asset_print_int(va_list args);
int asset_print_binary(va_list args);
int asset_print_unsigned(va_list args);
int asset_print_octal(va_list args);
int asset_print_hex(va_list args);
int asset_print_adress(va_list args);
int asset_print_reverse(va_list args);
int asset_print_string(va_list args);
int asset_print_hex_upper(va_list args);
int asset_print_percent(va_list args);


#endif
