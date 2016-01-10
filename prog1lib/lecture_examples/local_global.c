/*
Compile: make local_global
Run: ./local_global
*/

#include "base.h"

int g = 0;
const int G = 123;

int f(int a) {
	const int i = 3;
	return i * a;
}

int main(void) {
	x++;
	printiln(x);
	printiln(X);
	return 0;
}
