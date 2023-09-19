#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
void int_to_str(int num, char *str, int buffer_size);
int printf_unsigned(int val);
int printf_rot13(char* val);
int printf_dec(int val);
int printf_int(int val);
int printf_r(char* val);
int num_digits(int num);
int _putchar(char c);

#endif
