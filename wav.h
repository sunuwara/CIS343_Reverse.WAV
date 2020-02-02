/*	wav.h Header file
 * 	Authors: Aron Sunuwar & Karan Tamang 
 * */

#ifndef		__H_WAV__
#define		__H_WAV__

// .wav files header
typedef struct wav_file {
    char riff[4];						// "RIFF" string - always the same values
    int wav_size;						// chunk size of .wav file - 8 bytes
    char wave[4];						// "WAVE" string - don't use if it doesn't say this!
    char fmt[4];          				// "fmt " string has trailing null char
	int format_length;					// length of format section
	short format_type;					// format type: 1 for PCM, 3 for IEEE float
	short num_channels;					// number of channels
	int sample_rate;					// sample rate
	int byte_rate;						// byte rate: sample_rate * num_channels * (bits_per_sample / 8)
	short block_align;					// block alignment: num_channels * (bits_per_sample / 8)
	short bits_per_sample;				// bits per sample: 8bits, 16bits etc.
	char data[4];						// "data" string - beginning of data section
	int data_size;						// number of bytes in data section: num_samples * num_channels * (bits_per_sample / 8)
	char* actual_data;					// rest of the data
} wav_file;

// parse a .wav file
wav_file* parse(char* contents);

#endif // WAV_H_
