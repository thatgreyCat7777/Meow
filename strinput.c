#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strinput.h"

// Prompts the user for a string of text
char *getstring(const char *prompt, ...)
{
    va_list arglist;
    va_start(arglist, prompt);
    vprintf(prompt, arglist);
    va_end(arglist);
    int bfrsize = 100;
    int len = 0;
    char *str = calloc(bfrsize, sizeof(char));
    if (str == NULL)
    {
        return NULL;
    }
    for (char reader = getc(stdin); reader != '\n' && reader != EOF; reader = getc(stdin))
    {
        if (len >= bfrsize)
        {
            bfrsize *= 2;
            char *bfr = str;
            str = realloc(str, sizeof(char) * bfrsize);
            if (str == NULL)
            {
                free(bfr);
                return NULL;
            }
        }
        str[len] = reader;
        len++;
    }
    char *bfr = str;
    str = realloc(str, sizeof(char) * (len + 1));
    if (str == NULL)
    {
        free(bfr);
        return NULL;
    }
    str[len] = '\0';
    return str;
}
