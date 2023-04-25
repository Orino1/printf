#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
void _putchar(char c)
{
	write(1, &c, 1);
}
int _putnums(int num, int count) {
	if (num < 0) {
		_putchar('-');
		num = -num;
		count++;
	}
	if (num / 10 > 0) {
		count = _putnums(num / 10, count);
	}
	_putchar(num % 10 + '0');
	return count+1;
}
#include <stdarg.h>
#include <stddef.h>
int _printf(const char *format, ...)
{
	int i = 0;
	int j = 0;
	int result = 0;
	char *string;
	va_list args;
	if (format == NULL)
		return (-1);
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '\0')
			{
				if (format[i + 1] == 'c')
				{
					_putchar(va_arg(args, int));
					result++;
					i++;
				}
				else if (format[i + 1] == 's')
				{
					string = va_arg(args, char *);
					if (string != NULL)
					{
						for (j = 0; string[j] != '\0'; j++)
						{
							_putchar(string[j]);
							result++;
						}
					}
					i++;
				}
				else if (format[i + 1] == 'd')
				{
					result += _putnums(va_arg(args, int),result);
					i++;
				}
				else if (format[i + 1] == 'i')
                                {
                                        result += _putnums(va_arg(args, int),result);
                                        i++;
                                }
				else if (format[i + 1] == '%')
                                {
                                        _putchar('%');
                                        i++;
                                }
			}
		}
		else if (format[i] != '%')
		{
			_putchar(format[i]);
 			result++;
		}
		else if (format[i] == '\\')
		{
			if (format[i + 1] != '\0' && format[i + 1] == 'n')
			{
				_putchar('\n');
				result++;
				i++;
			}
		}
	}
	va_end(args);
	return (result);
}

#endif
