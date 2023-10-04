#include "libs.h"
#include "constants.h"

void show_file(char *filename)
{
    FILE *file = fopen(filename, "rb");
    struct person cur_person;

    for (size_t i = 0; 1; i++)
    {
        fread(&cur_person, sizeof(cur_person), 1, file);

        if (feof(file))
            break;

        printf("%s %s ", cur_person.lastname, cur_person.name);
        for (int i = 0; i < 4; i++)
        {
            printf("%d ", cur_person.marks[i]);
        }
        printf("\n");
    }

    fclose(file);
}