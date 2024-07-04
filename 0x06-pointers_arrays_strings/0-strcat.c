#include <stdio.h>

// Function to concatenate two strings
char *_strcat(char *dest, const char *src) {
    char *d = dest;
    
    // Find the end of the destination string
    while (*d != '\0') {
        d++;
    }
    
    // Copy the source string to the end of the destination string
    while (*src != '\0') {
        *d = *src;
        d++;
        src++;
    }
    
    // Add the null terminator at the end
    *d = '\0';
    
    return dest;
}

int main() {
    char dest[100] = "Hello, ";
    char src[] = "World!";
    
    printf("Before concatenation: %s\n", dest);
    _strcat(dest, src);
    printf("After concatenation: %s\n", dest);
    
    return 0;
}
