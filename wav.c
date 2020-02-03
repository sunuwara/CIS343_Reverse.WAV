/*	wav.c Source file
 * 	Authors: Aron Sunuwar & Karan Tamang 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wav.h"

// parse a .wav file
wav_file* parse(char* contents) {
    
    // Allocate memory space for *header
    wav_file* header = malloc(sizeof(wav_file));
    if (header == NULL) {
        fprintf(stderr, "malloc() failed: memory not allocated!\n");
        exit(EXIT_FAILURE);
    }

    // Copy header bytes of .wav file to wav file struct
    memcpy(header, contents, sizeof(wav_file));

    return header;
}
