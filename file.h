/*	file.h Header file
 *	
 * 	Authors: Aron Sunuwar & Karan Tamang 
 * */

#ifndef FILE_H_
#define FILE_H_

size_t read_file( char* filename, char **buffer);

size_t write_file( char* filename, char *buffer, size_t size);

#endif //FILE_H_
