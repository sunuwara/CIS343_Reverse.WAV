/*	file.c Source file
 * 	Authors: Aron Sunuwar & Karan Tamang 
 * */

#include <stdio.h>
#include <stdlib.h>
#include "file.h"

// Reads an input file
size_t read_file(char* filename, char** buffer) {
    FILE* fin;
    int fsize;

    // Open input file
    fin = fopen(filename, "rb");
    if (fin == NULL) {
        printf("Could not open input file!\n");
        exit(1);
    }

    // Find size of file
    fseek(fin, 0, SEEK_END);
    fsize = ftell(fin);
    fseek(fin, 0, SEEK_SET);

    // Allocate mem space for *buffer
    *buffer = malloc(fsize * sizeof(char));


}

// Write to an output file
size_t write_file(char* filename, char* buffer, size_t size) {

}