#include <stdio.h>

#define BUFFER_MAX 2048

// Defines max user input 
static char input[BUFFER_MAX];

int main (int argc, char** argv) {
	
	puts("Lispy Version 0.0.1");
	puts("Press Ctrl + c to Exit\n");
	
	// Infinite loop
	while (1) {
		
		// Output
		fputs("my_lisp> ", stdout);
		
		// Read user input
		fgets(input, BUFFER_MAX, stdin);
		
		printf("%s", input);
	}
	return 0;
}