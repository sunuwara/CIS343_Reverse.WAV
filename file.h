/*	file.h Header file
 *	
 * 	Authors: Aron Sunuwar & Karan Tamang 
 * */

#ifndef FILE_H_
#define FILE_H_

// reads an input file
size_t read_file(char* filename, char** buffer);

// write to an output file
size_t write_file(char* filename, char* buffer, size_t size);

#endif // FILE_H_