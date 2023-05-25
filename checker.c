#include <stdio.h>
#include <stdlib.h>

#include "macrouri.h"
#include "liner.h"
#include "byte_string.h"

void file_opener(char const *name_of_file)
{
    printf("Checking file %s\n", name_of_file);
    FILE *fin = fopen(name_of_file, "rt");
    if (!fin) {
        printf("Eroare la deschiderea fisierului");
        return;
    }

    char **txt = (char **)malloc(MAX_LIN * sizeof(char *));
    int mistakes = ZERO;
    for (int i = ZERO; i < MAX_LIN; i++)
        txt[i] = (char *)malloc(MAX_COL * sizeof(char));

    int nr_lines = ZERO;
    while (!feof(fin)) {
        fgets(txt[nr_lines], MAX_COL, fin);
        nr_lines++;
        if (nr_lines == MAX_LIN) {
            printf("Fisierul are prea multe linii pentru ca checkerul");
            printf(" sa le verifice pe toate.\n");
            break;
        }
    }

    int i = ZERO;
    while (i < nr_lines) {

        i = multiple_blank_lines(name_of_file, txt, nr_lines, i, &mistakes);
        void long_line(char const *f_name, char **txt, int idx, int *error);
        i++;
    }

    if (byteop_strlen(txt[nr_lines - UNU])) {
        printf("%s : ERROR : ", name_of_file);
        printf("expected new-line character at the end of the file.\n"); 
        mistakes++;
    }

    if (!mistakes) {
        printf("%s : seems ok, ", name_of_file);
        printf("but should also be checked manually. Good luck\n");
    } else {
        printf("In the file %s have been identified", name_of_file);
        printf(" %d coding style errors.\n\n", mistakes);
    }

    for (int i = ZERO; i < MAX_LIN; i++)
        free(txt[i]);
    free(txt);
    fclose(fin);
}

int main(int argc, char const *argv[])
{
    // primul parametru este executabili, indexat de la 0
    for (int i = UNU; i < argc; i++)
        file_opener(argv[i]);

    return 0;
}