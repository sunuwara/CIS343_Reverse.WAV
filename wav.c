/*	wav.c Source file
 * 	Authors: Aron Sunuwar & Karan Tamang 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wav.h"

// parse a .wav file
wav_file* parse(char* contents) {
    wav_file* header = malloc(sizeof(wav_file));
    memcpy(header, contents, 44);
    
    for (size_t i = 0; i < 44; i++) {
        printf("%d", contents[i]);
    }
    
    printf("\nRIFF - %s\n", header->riff);
    printf("size - %d\n", header->wav_size);
    printf("WAVE - %s\n", header->wave);
    printf("fmt  - %s\n", header->fmt);
    printf("format length - %d\n", header->format_length);
    printf("format type   - %hd\n", header->format_type);
    printf("# channels    - %hd\n", header->num_channels);
    printf("sample rate   - %d\n", header->sample_rate);
    printf("byte rate     - %d\n", header->byte_rate);
    printf("block align   - %hd\n", header->block_align);
    printf("bits / sample - %hd\n", header->bits_per_sample);
    printf("data - %s\n", header->data);
    printf("data size - %d\n\n", header->data_size);

    return header;
}