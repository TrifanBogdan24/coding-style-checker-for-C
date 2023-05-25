#include <stdio.h>

#include "macrouri.h"
#include "byte_string.h"
#include "liner.h"

#define NON_BLANK(c) ((c) ^ '\n') && ((c) ^ ' ')
#define CHAR_EGAL(c1, c2) ((c1) ^ (c2) ? 0 : 1)
#define ESTE_CIFRA(c) (('0' <= (c)) && ((c) <= '9') ? 1 : 0)

int blank_line(char *sir)
{
    for (int i = ZERO; i < byteop_strlen(sir); i++) {
        if (NON_BLANK(sir[i]))
            return ZERO; // linia nu este de tip blank-line
    }
    return UNU;  // linie de tip blank-line
}

int multiple_blank_lines(char const *f_name, char **txt, int nr_lines, int i, int *error)
{
    int j = i;
    int len = byteop_strlen(txt[j]);
    while (j < len && blank_line(txt[j]))
        j++;


    if (j > i + UNU) {
        printf("%s : ERROR : ", f_name);
        printf("multiple blank-lines from %d to %d\n", i + UNU, j);
        (*error)++;
    }
    return j;
}

void long_line(char const *f_name, char **txt, int nr_lines, int lin, int *error)
{
    int len = byteop_strlen(txt[lin]);
    if (len > OPT_ZECI) {
        printf("%s : ERROR : ", f_name);
        printf("line %d has a length of %d, ", lin + UNU, len);
        printf("bigger than %d.\n", OPT_ZECI);
        (*error)++;
    }
}

void comma(char const *f_name, char **txt, int nr_lines, int lin, int *error)
{
    int good = UNU; // nu verificam in interiorul ghilimelelor
    int len = byteop_strlen(txt[lin]);
    for (int i = ZERO; i < len; i++) {
        if (txt[lin][i] == '"')
            good = UNU - good;

        if (txt[lin][i] == ',' && good) {
            if (i > ZERO && CHAR_EGAL(txt[lin][i - UNU], ' ')) {
                printf("%s : ERROR : ", f_name);
                printf("line %d, column %i", lin + UNU, i + UNU);
                printf(" there should be no space(s) before a comma ','.\n");
                (*error)++;
            } 

            if (i < len - UNU && !CHAR_EGAL(txt[lin][i + UNU] ,' ')) {
                printf("%s : ERROR : ", f_name);
                printf("line %d, column %i", lin + UNU, i + DOI);
                printf(" expected a space ' ' after a comma ','.\n");
                (*error)++;
            }

            int j = i + UNU;
            while (j < len && CHAR_EGAL(txt[lin][j], ' '))
                j++;

            if (j > i + DOI) {
                printf("%s : ERROR : ", f_name);
                printf("line %d, column %d,", lin + UNU, i + UNU);
                printf(" too many spaces after the comma.\n");
                (*error)++;
            }
        }
    }
}

void trailing_whitespace(char const *f_name, char **txt, int nr_lines, int lin, int *error)
{
    int len = byteop_strlen(txt[lin]);
    
    if (len - UNU > ZERO && CHAR_EGAL(txt[lin][len- DOI], ' ')) {
        // daca col = 0, atunci blank line, care este deja verificat
        printf("%s : ERROR : ", f_name);
        printf("line %d trailing whitespaces", lin + UNU);
        printf(" at the end of the line.\n");
        (*error)++;
    }
}