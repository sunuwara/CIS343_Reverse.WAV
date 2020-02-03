#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "wav.h"

int main(int argc, char** argv) {
    char* buffer;
    char* reverse_buffer;
    int size;
    wav_file* header;

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
    printf("===================\n");
    printf("- File size is %d. Read %d bytes.\n", header->wav_size, size);
    printf("- Format is \"%s\" with format data length %d.\n", header->fmt, header->format_length);
    printf("- Format type is %s.\n", header->wave);
    printf("- %hd channel(s) with a sample rate of %d.\n", header->num_channels, header->sample_rate);
    printf("- %d byte rate, %d alignment,", header->byte_rate, header->block_align);
    printf(" %d bits per sample.\n", header->bits_per_sample);
    printf("- Data is \"%s\" and data size is %d.\n", header->data, header->data_size);

    // Reversing file
    reverse_buffer = buffer;
    for(int i = 0; i < (size - 44); i += 2) {
        (reverse_buffer)[44 + i] = (buffer)[size - (1 + i)];
        (reverse_buffer)[45 + i] = (buffer)[size - i];
    }

    // Write file
    write_file(argv[2], reverse_buffer, size);

    free(buffer);
    free(header);
    return 0;
}
