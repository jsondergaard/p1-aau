/*

	main.c -- Template main()

	Copyright © 2015-2016 Fletcher T. Penney.


	This program is free software you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation either version 2 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program if not, write to the Free Software
	Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "d_string.h"

#define kBUFFERSIZE 4096	// How many bytes to read at a time

DString * stdin_buffer() {
	/* Read from stdin and return a GString *
		`buffer` will need to be freed elsewhere */

	char chunk[kBUFFERSIZE];
	size_t bytes;

	DString * buffer = d_string_new("");

	while ((bytes = fread(chunk, 1, kBUFFERSIZE, stdin)) > 0) {
		d_string_append_c_array(buffer, chunk, bytes);
	}

	fclose(stdin);

	return buffer;
}

DString * scan_file(char * fname) {
	/* Read from stdin and return a GString *
		`buffer` will need to be freed elsewhere */

	char chunk[kBUFFERSIZE];
	size_t bytes;

	FILE * file;

	if ((file = fopen(fname, "r")) == NULL ) {
		return NULL;
	}

	DString * buffer = d_string_new("");

	while ((bytes = fread(chunk, 1, kBUFFERSIZE, file)) > 0) {
		d_string_append_c_array(buffer, chunk, bytes);
	}

	fclose(file);

	return buffer;
}

void calender(int calenderArray[][], int rows, int collums);

int main( int argc, char** argv ) {
	/* Make your program do whatever you want */
    int const collums = 7;
    int const rows = 5;
    int calenderArray[rows][collums]={
            {1,2,3,4,5,6,7},
            {5,6,7,8,9,10,11},
            {12,13,14,15,16,17,18},
            {19,20,21,22,23,24,25},
            {26,27,28,29,30,31,0}
    };
    calender(calenderArray[][], rows, collums);
}

void calender(int calenderArray[][], int rows, int collums){


    for (int i = 0; i < rows; i++){
        for (int j = 0; j < collums; j++){
            printf("%d ", calenderArray[i][j]);
        }
        printf("\n");
    }

}

