#include <stdio.h>

void modifyValue(int *ptr) {
    *ptr = 100;
}

int main() {
    int num = 42;
    
    printf("Before function call: %d\n", num);
    
    modifyValue(&num);  // Pass the address of 'num'
    
    printf("After function call: %d\n", num);  // Output: 100
    
    return 0;
}