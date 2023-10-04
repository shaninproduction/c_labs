#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *filet = fopen(argv[1], "r");
    FILE *fileb = fopen("bfile.bin", "wb");

    int num; 

    for (size_t i = 0; 1; i++)
    {
        fscanf(filet, "%d", &num);

        if (feof(filet))
            break;
        
        fwrite(&num, sizeof(num), 1, fileb);
    }
    

    fclose(fileb);
    fclose(filet);
    return EXIT_SUCCESS;
}