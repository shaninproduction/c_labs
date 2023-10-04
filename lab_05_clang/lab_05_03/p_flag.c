#include "libs.h"

// Функция вывода содержимого файла
void show_file(char *file_name)
{
    int num;
    FILE *file = fopen(file_name, "rb");

    printf("Your bin file : ");
    for (int i = 0; 1; i++)
    {
        fread(&num, sizeof(int), 1, file);

        if (feof(file))
            break;

        printf("%d ", num);
    }
    printf("\n");

    fclose(file);
}