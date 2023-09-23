#include <stdio.h>

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    int *ptr = numbers;  // Pointer to the first element of the array
    
    printf("Value at ptr: %d\n", *ptr);  
    printf("Memory address of %d = %p, %llu\n", *ptr, ptr, (unsigned long long)ptr);
    ptr++;  // Move the pointer to the next element
    printf("Value at ptr: %d\n", *ptr);  
    
    printf("Memory address of %d = %p, %llu\n", *ptr, ptr, (unsigned long long)ptr);
    printf("Memory address of %d = %p\n", *ptr, (void *)ptr);
    printf("Memory address of %p = %p\n", ptr, (void *)&ptr);

    ptr+=2;
    printf("\n");
    printf("Value at ptr: %d\n", *ptr);  
    printf("Memory address of %d = %p, %llu\n", *ptr, ptr, (unsigned long long)ptr);
    printf("Memory address of %d = %p\n", *ptr, (void *)ptr);
    printf("Memory address of %p = %p\n", ptr, (void *)&ptr);

    return 0;
}

/*
Q)Shouldn't we have written int *ptr = &numbers; just like in the previous one where we wrote int *ptr=&num ?
Ans)No, in the case of an array, the name of the array itself represents the address of the first element of the array. So, when you write `int *ptr = numbers;`, you are assigning the address of the first element of the `numbers` array to the `ptr` pointer. This is equivalent to writing `int *ptr = &numbers[0];`.

On the other hand, if you write `int *ptr = &numbers;`, you are assigning the address of the entire `numbers` array to the `ptr` pointer, which is not what you want in this case. The type of `&numbers` is `int (*)[5]`, which is a pointer to an array of 5 integers, whereas the type of `ptr` is `int *`, which is a pointer to an integer. These types are not compatible and attempting to assign one to the other would result in a compiler error.

Q)Here why the value of (void *)&ptr did not change ?
Ans)In the code you provided, the value of `(void *)&ptr` did not change because `&ptr` represents the memory address of the `ptr` variable itself, which does not change throughout the program. The `ptr` variable is a pointer that stores the memory address of an element in the `numbers` array. When you increment or decrement the `ptr` pointer using statements like `ptr++` or `ptr+=2`, you are changing the value stored in the `ptr` pointer, not its memory address.

On the other hand, `(void *)ptr` represents the value stored in the `ptr` pointer, which is the memory address of an element in the `numbers` array. When you increment or decrement the `ptr` pointer, this value changes to point to a different element in the array.
*/