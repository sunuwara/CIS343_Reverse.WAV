/*	main.c Source file
 * 	Authors: Aron Sunuwar & Karan Tamang 
 * 
 *  This program takes an input .wav file and will output a .wav file
 *  that has the audio reversed.
 * */

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "file.h"
#include "wav.h"

int main(int argc, char** argv) {
   
    char* buffer;
    char* reversed_buffer;
    int size;
    wav_file* header;
    int bytes_per_sample;

    // Invalid arguments error catching
    if (argc != 3) {
        if (argc < 2)
            fprintf(stderr, "Invalid argument: Expecting input and output .wav file!\n");
        else if (argc > 3) 
            fprintf(stderr, "Invalid argument: Too many arguments!\n");
        else
            fprintf(stderr, "Invalid argument: Expecting output .wav file!\n");
        
        exit(EXIT_FAILURE);
    }

    // Read input file
    size = read_file(argv[1], &buffer);

    // Parse the buffer into wav_file header
    header = parse(buffer);

    // Output file statistics:
    printf("File: %s\n", argv[1]);
    printf("=========================================================\n");
    printf("- File size is %d. Read %d bytes.\n", header->wav_size, size);
    printf("- Format is \"%.4s\" with format data length %d.\n", header->fmt, header->format_length);
    printf("- Format type is %.4s.\n", header->wave);
    printf("- %hd channel(s) with a sample rate of %d.\n", header->num_channels, header->sample_rate);
    printf("- %d byte rate, %d alignment, %d bits per sample.\n", header->byte_rate, header->block_align, header->bits_per_sample);
    printf("- Data is \"%.4s\" and data size is %d.\n", header->data, header->data_size);

    //Allocate memory space for *reversed_buffer
    reversed_buffer = malloc(size * sizeof(char));
    if (reversed_buffer == NULL) {
        fprintf(stderr, "malloc() failed: memory not allocated!\n");
        exit(EXIT_FAILURE);
    }

    // Copy header bytes to reversed buffer
    memcpy(reversed_buffer, header, sizeof(wav_file));       

    // Reversing audio data
    for(int i = 0; i < (size - 44); i += (header->bits_per_sample / 8)) {
        reversed_buffer[44 + i] = buffer[size - (2 + i)];
        reversed_buffer[45 + i] = buffer[size - (1 + i)];
    }

    // Write to output file
    write_file(argv[2], reversed_buffer, size);

    free(buffer);
    free(reversed_buffer);
    free(header);
    return 0;
}