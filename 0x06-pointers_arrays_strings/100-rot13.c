#include <stdio.h>

char *rot13(char *str) {
    char *p = str;
    char alphabet[52] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char rot13[52] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
    int i;

    while (*p) {
        for (i = 0; i < 52; i++) {
            if (*p == alphabet[i]) {  // The single if statement
                *p = rot13[i];
                break;
            }
        }
        p++;
    }
    return str;
}

int main() {
    char str[] = "Hello, World!";
    printf("Original: %s\n", str);
    printf("ROT13: %s\n", rot13(str));
    printf("Back to original: %s\n", rot13(str));  // Applying ROT13 again to decode
    return 0;
}
