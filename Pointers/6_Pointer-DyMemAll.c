// Dynamic Memory Allocation - You can allocate memory dynamically using functions like malloc, calloc, and deallocate using free.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int size = 5;
    
    arr = (int *)malloc(size * sizeof(int));  // Allocate memory
    
    for (int i = 0; i < size; i++) {
        arr[i] = i * 10;
    }
    
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = %d and their address = %p = %p\n", i, arr[i], &arr[i], arr+i);
    }
    
    free(arr);  // Deallocate memory
    
    return 0;
}

/**
*! Q)What is (int *) in (int *)malloc(size * sizeof(int)); 
*? Ans)`(int *)` in `(int *)malloc(size * sizeof(int))` is a type cast operator that converts the type of the expression that follows it to the specified type. In this case, it is used to convert the return value of the `malloc` function, which is a `void *`, to an `int *`.

*? The `malloc` function is used to allocate memory dynamically at runtime. It takes as an argument the number of bytes to allocate and returns a pointer to the first byte of the allocated memory block. The type of this pointer is `void *`, which means that it can point to an object of any type.

However, in C, pointer arithmetic and array indexing are only defined for pointers to complete object types, not for `void *` pointers. This means that if you want to use a `void *` pointer returned by `malloc` to access the elements of an array, you need to convert it to a pointer to the appropriate element type first.

*? In the code you provided, `(int *)malloc(size * sizeof(int))`, the `malloc` function is used to allocate memory for an array of `size` integers. The size of each integer is obtained using the `sizeof` operator and multiplied by the number of elements in the array to calculate the total number of bytes to allocate. The return value of the `malloc` function is then cast to an `int *` using the `(int *)` type cast operator, so that it can be used to access the elements of the allocated integer array.
*/