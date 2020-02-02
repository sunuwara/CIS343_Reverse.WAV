#include <stdio.h>
#include <stdlib.h>
#include "file.h"

int main(int argc, char** argv) {

    // int num;
    // FILE *fptr;
    char* buffer;
    size_t size;
    
    printf("Wav Read Test\n");
    
    if (argc < 2) {
        printf("Expecting wav file as argument!\n");
        exit(1);
    }
    
    // Read file
    size = read_file(argv[1], &buffer);

    // Write file
    write_file(argv[2], buffer, size);

    // printf("%lu\n", size);

    // fscanf(fptr, "%d", &num);
    // printf("File: %s", &fileName);
    // printf("===================");
    // printf("- File size is %d. Read %d bytes", &size, &bytes);
    // printf("- Format is \"%c \" with format data length %d.", &format, &length);
    // printf("- Format type is %s", % fmtType);
    // printf("- %d channels with a sample rate of %d", &channel, &rate);
    // printf("- %d byte rate, %d alignment, %d bits per sample.", );
    // printf("- Data is \"data\" and data size is %d", &dataSize);
    // fclose(fptr);

    free(buffer);
    return 0;
}

