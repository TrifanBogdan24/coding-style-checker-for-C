#include <stdio.h>

#include "macrouri.h"
#include "byte_string.h"
#include "liner.h"

#define NON_BLANK(c) ((c) ^ '\n') && ((c) ^ ' ')

int blank_line(char *sir)
{
    for (int i = ZERO; i < byteop_strlen(sir); i++) {
        if (NON_BLANK(sir[i]))
            return ZERO; // linia nu este de tip blank-line
    }
    return UNU;  // linie de tip blank-line
}

int multiple_blank_lines(char const *f_name, char **txt, int nr_lin, int i, int *error)
{
    int j = i;
    while (j < nr_lin && blank_line(txt[j]))
        j++;


    if (j > i + UNU) {
        printf("%s : ERROR : ", f_name);
        printf("multiple blank-lines from %d to %d\n", i + UNU, j);
        (*error)++;
    }
    return j;
}

void long_line(char const *f_name, char **txt, int idx, int *error)
{
    int len = byteop_strlen(txt[idx]);
    if (len > OPT_ZECI) {
        printf("%s : ERROR : ", f_name);
        printf("line %d has a length of %d, ", idx + UNU, len);
        printf("bigger than %d.\n", OPT_ZECI);
        (*error)++;
    }
}

void comma(char const *f_name, char **txt, int idx, int *error)
{
    
}