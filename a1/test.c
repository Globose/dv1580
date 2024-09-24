#include <stdio.h>
#include <string.h>  // For memcpy

int main() {
    // Source array
    char src[] = "Hello, World!";
    
    // Destination array - make sure it's large enough to hold the data
    char dest[20];  // Allocate sufficient space

    // Copy the content of src to dest using memcpy
    memcpy(dest, src, strlen(src) + 1);  // +1 to include the null-terminator '\0'

    // Print out both source and destination to check
    printf("Source: %s\n", src);
    printf("Destination: %s\n", dest);

    return 0;
}
