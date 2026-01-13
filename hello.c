#include "strinput.h"
#include <stdio.h>


int main()
{
    char *name = getstring("Name: ");
    printf("Hello, %s", name);
    
}