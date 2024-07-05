#include <stdio.h>
#include <ctype.h>

void print_buffer(char *b, int size) {
    int offset, i;
    
    if (size <= 0) {
        printf("\n");
        return;
    }

    for (offset = 0; offset < size; offset += 10) {
        printf("%08x: ", offset);

        // Print the hex content
        for (i = 0; i < 10; i++) {
            if (offset + i < size) {
                printf("%02x", (unsigned char)b[offset + i]);
            } else {
                printf("  ");
            }
            if (i % 2 != 0) {
                printf(" ");
            }
        }

        // Print the ascii content
        for (i = 0; i < 10; i++) {
            if (offset + i < size) {
                if (isprint((unsigned char)b[offset + i])) {
                    printf("%c", b[offset + i]);
                } else {
                    printf(".");
                }
            }
        }
        printf("\n");
    }
}

int main() {
    char buffer[] = "This is a sample buffer for testing the print_buffer function. Let's see how it looks!";
    int size = sizeof(buffer) - 1;  // exclude the null terminator

    print_buffer(buffer, size);

    return 0;
}
