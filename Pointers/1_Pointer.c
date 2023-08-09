/*
A pointer is a variable that holds the memory address of another variable. It allows you to indirectly access and manipulate data in memory.
*/

#include <stdio.h>

int main() {
    int num = 42;
    int *ptr;  // Declare a pointer to an integer
    
    ptr = &num;  // Assign the address of 'num' to the pointer
    
    printf("Value of num: %d\n", num); 
    printf("Value of num using pointer: %d\n", *ptr);  // Dereference the pointer to access the value
    printf("Memory address = %p\n", ptr); 
    printf("Memory address = %p\n", &num); 
    printf("Memory address in decimal notation = %d\n", ptr);
    printf("Memory address of ptr itself in hehxadecimanl notation : %p\n", (void *)&ptr);
    return 0;
}

/*
%d format specifier is used with the printf function to print an integer value in decimal notation
%p  is typically used to display the memory address stored in a pointer variable

If you want to print the memory address of the pointer variable ptr itself, you can use the & operator to get the address of ptr and then use the %p format specifier with the printf function to print it in hexadecimal notation. Note that we need to cast the address of ptr to a void * pointer before passing it to printf, as the %p format specifier expects a void * argument. 
*/