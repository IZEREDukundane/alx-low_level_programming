#include <stdio.h>
#include <string.h>

char *infinite_add(char *n1, char *n2, char *r, int size_r) {
    int len1 = strlen(n1);
    int len2 = strlen(n2);
    int carry = 0;
    int sum;
    int i = len1 - 1, j = len2 - 1, k = 0;

    // Buffer size must be able to hold the maximum result length + 1 for null terminator
    if (size_r <= len1 || size_r <= len2) {
        return 0;
    }

    // Perform addition from the end of n1 and n2
    while (i >= 0 || j >= 0 || carry) {
        if (i >= 0) {
            sum = n1[i] - '0' + carry;
        } else {
            sum = carry;
        }

        if (j >= 0) {
            sum += n2[j] - '0';
        }

        carry = sum / 10;
        sum = sum % 10;

        // Check if the buffer is exhausted
        if (k >= size_r - 1) {
            return 0;
        }

        r[k] = sum + '0';
        k++;
        i--;
        j--;
    }

    // Null terminate the result
    r[k] = '\0';

    // Reverse the result since it's stored backwards
    for (int start = 0, end = k - 1; start < end; start++, end--) {
        char temp = r[start];
        r[start] = r[end];
        r[end] = temp;
    }

    return r;
}

int main() {
    char n1[] = "12345";
    char n2[] = "67890";
    char result[100];
    char *res = infinite_add(n1, n2, result, 100);

    if (res) {
        printf("Sum: %s\n", res);
    } else {
        printf("Buffer too small\n");
    }

    return 0;
}
