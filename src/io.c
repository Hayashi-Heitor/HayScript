#include "include/io.h"
#include <stdio.h>
#include <stdlib.h>


// Reads entire file contents into memory
char *getFileContents(const char *filePath) {
    char *buffer = NULL;  // Output buffer
    long length;          // File size
    
    // Open file in binary mode
    FILE *file = fopen(filePath, "rb");

    if(file) {
        // Gets file size by seeking to end
        fseek(file, 0, SEEK_END);
        length = ftell(file);
        fseek(file, 0, SEEK_SET);

        // Allocate buffer matching file size
        buffer = calloc(length, sizeof(char));

        if(buffer) {
            // Read entire file into buffer
            fread(buffer, 1, length, file);
        }
        
        // Cleanup file handle
        fclose(file);
        return buffer;
    }

    // Error handling
    printf("Error reading file: %s\n", filePath);
    exit(2);
}