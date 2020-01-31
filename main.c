#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv)
{
    int num;
    FILE *fptr;
    printf("Wav Read Test\n");
    if (argc != 2)
    {
        fprintf(stderr, "Expecting wav file as argument\n");
        return 1;
    }
    
    fscanf(fptr, "%d", &num);
    printf("File: %s", &fileName);
    printf("===================");
    printf("- File size is %d. Read %d bytes", &size, &bytes);
    printf("- Format is \"%c \" with format data length %d.", &format, &length);
    printf("- Format type is %s", % fmtType);
    printf("- %d channels with a sample rate of %d", &channel, &rate);
    printf("- %d byte rate, %d alignment, %d bits per sample.", );
    printf("- Data is \"data\" and data size is %d", &dataSize);
    fclose(fptr);

    return 0;
}
