#include <stdio.h>

// Prototype for the _putchar function
int _putchar(char c);

// Function to print an integer
void print_number(int n) {
    // Handle negative numbers
    if (n < 0) {
        _putchar('-');
        n = -n;
    }

    // Handle the number printing using recursion
    if (n / 10 != 0) {
        print_number(n / 10);
    }

    // Print the last digit
    _putchar((n % 10) + '0');
}

// Mock implementation of _putchar
// Replace this with the actual _putchar function
int _putchar(char c) {
    return putchar(c);
}

int main() {
    print_number(98);
    _putchar('\n');
    print_number(402);
    _putchar('\n');
    print_number(1024);
    _putchar('\n');
    print_number(0);
    _putchar('\n');
    print_number(-98);
    _putchar('\n');

    return 0;
}

