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
        fprintf(stderr, "Error: Could not open %s input file!\n", filename);
        exit(EXIT_FAILURE);
    }

    // Find size of file
    fseek(fin, 0, SEEK_END);
    fsize = ftell(fin);
    fseek(fin, 0, SEEK_SET);

    // Allocate memory space for *buffer
    *buffer = malloc(fsize * sizeof(char));
    if (buffer == NULL) {
        fprintf(stderr, "malloc() failed: memory not allocated!\n");
        exit(EXIT_FAILURE);
    }

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
        fprintf(stderr, "Error: Could not open %s output file!\n", filename);
        exit(EXIT_FAILURE);
    }

    // Write from buffer to output file
    for (int i = 0; i < size; ++i)
        fprintf(fout, "%c", buffer[i]);

    fclose(fout);
    return 0;
}