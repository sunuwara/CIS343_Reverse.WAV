/*	file.h Header file
 * 	Authors: Aron Sunuwar & Karan Tamang 
 * */

#ifndef		__FILE_H__
#define		__FILE_H__

// reads an input file
size_t read_file(char* filename, char** buffer);

// write to an output file
size_t write_file(char* filename, char* buffer, size_t size);

#endif		//__FILE_H__