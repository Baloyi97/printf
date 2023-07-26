#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/

/**
 * print_unsigned - Prints  unsigned number
 * @types: List arguments
 * @buffer: Buffer array to be handled by print
 * @flags:  Calc flags
 * @width: Get the width
 * @precision: Specification
 * @size: Size of specifier
 * Return: Number of characters printed.
 */

int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL NOTATION  ****************/

/**
 * print_octal - Prints unsigned number in octal notation
 * @types: List arguments
 * @buffer: Buffer array to be handled by print
 * @flags:  Calc flags
 * @width: Get the width
 * @precision: Specification
 * @size: Size of specifier
 * Return: Number of characters printed
 */

int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL NOTATION **************/

/**
 * print_hexadecimal - Prints  unsigned number in hexadecimal notation
 * @types: List arguments
 * @buffer: Buffer array to be handled by print
 * @flags:  Calc flags
 * @width: Get the width
 * @precision: Specification
 * @size: Size of specifier
 * Return: Number of characters printed
 */

int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL NOTATION **************/

/**
 * print_hexa_upper - Print unsigned number in upper hexadecimal notation
 * @types: List arguments
 * @buffer: Buffer array to be handled by print
 * @flags:  Calc flags
 * @width: Get the width
 * @precision: Specification
 * @size: Size of specifier
 * Return: Number of characters printed
 */

int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINT HEXADECIMAL NUM IN LOWER OR UPPER **************/

/**
 * print_hexa - Print hexadecimal number in lower or upper case
 * @types: Lista of arguments
 * @map_to: Array of values to map a number 
 * @buffer: Buffer array to be handled by print
 * @flags:  Calc flags
 * @flag_ch: Calc active flags
 * @width: Get the width
 * @precision: Specification
 * @size: Specifier
 * @size: Size of specification
 * Return: Number of characters printed
 */

int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
