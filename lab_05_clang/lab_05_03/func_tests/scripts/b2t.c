#include <stdio.h>
#include <stdlib.h>

#define NUM_LEN 100

int main(int argc, char **argv)
{
    FILE *fileb = fopen(argv[1], "rb");
    FILE *filet = fopen("tfile.txt", "w");

    int num; 

    for (size_t i = 0; 1; i++)
    {
        fread(&num, sizeof(num), 1, fileb);

        if (feof(fileb))
            break;
        
        fprintf(filet, "%d\n", num);
    }
    

    fclose(fileb);
    fclose(filet);
    return EXIT_SUCCESS;
}