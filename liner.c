#include <stdio.h>

#include "macrouri.h"
#include "byte_string.h"
#include "liner.h"

#define NON_BLANK(c) ((((c) ^ '\n') && ((c) ^ ' ')) ? 0 : 1)

int blank_line(char *sir)
{
    for (int i = ZERO; i < byteop_strlen(sir); i++) {
        if (NON_BLANK(sir[i]))
            return UNU; // linia nu este de tip blank-line
    }
    return ZERO;  // linie de tip blank-line
}
