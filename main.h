#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>


int _printf(const char *format, ...);
int _format(const char *format, va_list args, int *num);
void unkown_specif(int *num);
void handle_string(const char *str, int *num);



#endif
