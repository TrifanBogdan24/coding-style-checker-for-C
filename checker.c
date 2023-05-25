#include <stdio.h>
#include <stdlib.h>

#define ZERO 0

void file_opener(char const *name_of_file)
{
    printf("%s ", name_of_file);
    FILE *fin = fopen(name_of_file, "rt");
    if (!fin) {
        printf("Eroare la deschiderea fisierului");
        return;
    }

}

int main(int argc, char const *argv[])
{
    for (int i = ZERO; i < argc; i++)
        file_opener(argv[i]);

    return 0;
}