#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "http_head_struct.h"

//return NULL if str at the last line
static char* jump_to_next_line(char* str)
{
    while(*str != '\r') {
        if (*str == '\0') {
            return NULL;
        }
        str++;
    }

    if (str == '\r') {
        return *(str + 2) == '\r'? NULL : (str+2);
    } else {
        return NULL;
    }
}


//return -1 for Error!
static int line_length(char *str)
{
    int length = 0;
    while (str != '\r') {
        length++;
        if (*str == '\0') {
            return -1;
        }
    }
    return 0;
}
