#include <stdio.h>

int main() {
    int num = 42;
    int *ptr1 = &num;
    int **ptr2 = &ptr1;  // Pointer to a pointer
    
    printf("Value of num: %d\n", num);
    printf("Value of num using ptr1: %d\n", *ptr1);
    printf("Value of num using ptr2: %d\n", **ptr2);
    printf("\n");

    printf("Value of address of %d in ptr1 = %p\n", *ptr1, ptr1);
    printf("Value of address of %p in ptr2 = %p\n", ptr1, ptr2);
    printf("Value of address of %d in %p\n", **ptr2, *ptr2);
    printf("\n");

    printf("Address of %d = %p\n", num, &num);
    printf("Address of (ptr1) %p = %p\n", ptr1, &ptr1);
    printf("Address of (ptr2) %p = %p\n", ptr2, &ptr2);
    return 0;
}

/*
ptr1 holds the address of 42. *ptr holds the number 42
ptr2 holds the address of ptr1. *ptr2 holds the address of 42. **ptr2 holds the number 42
*/