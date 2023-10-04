#include "libs.h"
#include "constants.h"

double get_avg_mark(uint32_t marks[])
{
    int summa = 0;
    double avg;

    for (int i = 0; i < MARKS; i++)
    {
        summa += (int) marks[i];
    }
    
    avg = summa / MARKS;

    return avg;
}

double get_avg_all(char *filename, int length)
{
    struct person cur;
    FILE *file = fopen(filename, "rb");
    
    double avg, summa = 0;

    for (int i = 0; i < length; i++)
    {
        fread(&cur, sizeof(cur), 1, file);

        summa += get_avg_mark(cur.marks);
    }
    
    avg = (double) summa / length;
    fclose(file);
    return avg;
}

int delete_person(char *filename, int length)
{
    double avg = get_avg_all(filename, length);
    FILE *file = fopen(filename, "r+b");
    struct person cur, next;

    for (int i = 0; i < length; i++)
    {
        fread(&cur, sizeof(cur), 1, file);

        if (get_avg_mark(cur.marks) < avg)
        { 
            for (int j = i; j < length - 1; j++)
            {
                fread(&next, sizeof(next), 1, file);
                fseek(file, -2 * sizeof(cur), SEEK_CUR);
                fwrite(&next, sizeof(next), 1, file);
                fseek(file, 1 * sizeof(cur), SEEK_CUR);
            }
            
            fseek(file, i * sizeof(cur), SEEK_SET);
            length--;
            i--;
        }
    }

    ftruncate(fileno(file), length * sizeof(cur));
    fclose(file);
    return EXIT_SUCCESS;
}

