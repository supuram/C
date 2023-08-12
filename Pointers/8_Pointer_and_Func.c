#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int calculate(int (*operation)(int, int), int x, int y) {
    return operation(x, y);
}

int main() {
    int result;
    
    result = calculate(add, 10, 5);
    printf("Addition result: %d\n", result);
    
    result = calculate(subtract, 10, 5);
    printf("Subtraction result: %d\n", result);
    
    return 0;
}