#include <stdio.h>

int main() {
    char *str = "Hello, World!";
    printf("String = %c\n", *str);
    printf("Address of the string %c = %p\n", *str, str);
    // Print the string using a pointer
    while (*str != '\0') {
        printf("%c", *str);
        str++;
    }
    return 0;
}