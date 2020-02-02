/*	file.c Source file
 * 	Authors: Aron Sunuwar & Karan Tamang 
 * */

#include <stdio.h>
#include <stdlib.h>
#include "file.h"

// Reads an input file
size_t read_file(char* filename, char** buffer) {
    
    FILE *fin;
    int fsize;

    // Open read file
    fin = fopen(filename, "rb");
    if (fin == NULL) {
        printf("--- Could not open input file!\n");
        exit(1);
    }

    // Find size of file
    fseek(fin, 0, SEEK_END);
    fsize = ftell(fin);
    fseek(fin, 0, SEEK_SET);

    // Allocate mem space for *buffer
    *buffer = malloc(fsize * sizeof(char));

    // Read input file to a buffer
    fread(*buffer, sizeof(char), fsize, fin);

    fclose(fin);
    return fsize;
}

// Write to an output file
size_t write_file(char* filename, char* buffer, size_t size) {
    
    FILE *fout;

    // Open write file
    fout = fopen(filename, "wb");
    if (fout == NULL) {
        printf("--- Could not open output file!\n");
        exit(1);
    }

    // Write from buffer to output file
    for (int i = 0; i < size; ++i)
        fprintf(fout, "%c", buffer[i]);

    fclose(fout);
    return 0;
}