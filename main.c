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
    if (argc < 3) {
        if (argc < 2)
            printf("--- Expecting input .wav file as 1st argument!\n");
        else
            printf("--- Expecting output .wav file as 2nd argument!\n");
        
        exit(1);
    }

    // Read file
    size = read_file(argv[1], &buffer);

    // Parse the buffer
    header = parse(buffer);

    // Output file statistics:
    printf("File: %s\n", argv[1]);
    printf("=========================================================\n");
    printf("- File size is %d. Read %d bytes.\n", header->wav_size, size);
    printf("- Format is \"%s\" with format data length %d.\n", header->fmt, header->format_length);
    printf("- Format type is %s.\n", header->wave);
    printf("- %hd channel(s) with a sample rate of %d.\n", header->num_channels, header->sample_rate);
    printf("- %d byte rate, %d alignment,", header->byte_rate, header->block_align);
    printf(" %d bits per sample.\n", header->bits_per_sample);
    printf("- Data is \"%s\" and data size is %d.\n", header->data, header->data_size);

    // Reversing file
    reversed_buffer = malloc(size * sizeof(char));
    
    memcpy(reversed_buffer, header, sizeof(wav_file));       // copy the header to reversed buffer

    // reversing audio data
    for(int i = 0; i <= (size - 44); i += (header->bits_per_sample / 8)) {
        reversed_buffer[44 + i] = buffer[size - (2 + i)];
        reversed_buffer[45 + i] = buffer[size - (1 + i)];
    }

    // Write file
    write_file(argv[2], reversed_buffer, size);

    free(buffer);
    free(reversed_buffer);
    free(header);
    return 0;
}