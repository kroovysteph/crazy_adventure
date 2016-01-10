/*
Compile: make read_write_file
Run: ./read_write_file
*/

//#include "base.h"
#include "string.h"

int main(void) {
	String s = s_read_file("read_write_file.c");
	printf("This file has %d characters.\n", s_length(s));
	String t = s_upper_case(s);
	s_write_file("MY_UPPER.TXT", t);
	return 0;
}
