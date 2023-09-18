# Printf Project

printf, fprintf, dprintf, sprintf, snprintf, vprintf, vfprintf, vdprintf, vsprintf, vsnprintf - formatted output conversion

# SYNOPSIS
       #include <stdio.h>

       int printf(const char *format, ...);
       int fprintf(FILE *stream, const char *format, ...);
       int dprintf(int fd, const char *format, ...);
       int sprintf(char *str, const char *format, ...);
       int snprintf(char *str, size_t size, const char *format, ...);

       #include <stdarg.h>

       int vprintf(const char *format, va_list ap);
       int vfprintf(FILE *stream, const char *format, va_list ap);
       int vdprintf(int fd, const char *format, va_list ap);
       int vsprintf(char *str, const char *format, va_list ap);
       int vsnprintf(char *str, size_t size, const char *format, va_list

# DESCRIPTION
       The  functions  in  the  printf()  family  produce  output  according to a format as described below.  The functions printf() and
       vprintf() write output to stdout, the standard output stream; fprintf() and vfprintf() write output to the given  output  stream;
       sprintf(), snprintf(), vsprintf() and vsnprintf() write to the character string str.

       The function dprintf() is the same as fprintf() except that it outputs to a file descriptor, fd, instead of to a stdio stream.

       The functions snprintf() and vsnprintf() write at most size bytes (including the terminating null byte ('\0')) to str.

       The  functions  vprintf(),  vfprintf(),  vdprintf(), vsprintf(), vsnprintf() are equivalent to the functions printf(), fprintf(),
       dprintf(), sprintf(), snprintf(), respectively, except that they are called with a va_list instead of a variable number of  argu‐
       ments.   These  functions do not call the va_end macro.  Because they invoke the va_arg macro, the value of ap is undefined after
       the call.  See stdarg(3).

# Format of the format string
       The  format string is a character string, beginning and ending in its initial shift state, if any.  The format string is composed
       of zero or more directives: ordinary characters (not %), which are copied unchanged to the output stream; and conversion specifi‐
       cations, each of which results in fetching zero or more subsequent arguments.  Each conversion specification is introduced by the
       character %, and ends with a conversion specifier.  In between there may be (in this order) zero or more flags, an optional mini‐
       mum field width, an optional precision and an optional length modifier.

# RETURN VALUE
       Upon successful return, these functions return the number of characters printed (excluding the null byte used to  end  output  to
       strings).

       The  functions snprintf() and vsnprintf() do not write more than size bytes (including the terminating null byte ('\0')).  If the
       output was truncated due to this limit, then the return value is the number of characters (excluding the terminating  null  byte)
       which would have been written to the final string if enough space had been available.  Thus, a return value of size or more means
       that the output was truncated.  (See also below under NOTES.)

       If an output error is encountered, a negative value is returned.
