#include <stdio.h>

struct Point {
    int x;
    int y;
};

int main() {
    struct Point p1 = {10, 20};
    struct Point *ptr = &p1;
    
    printf("Coordinates: (%d, %d)\n", ptr->x, ptr->y);
    printf("Address of %d is %p\n", p1.y, &p1.y);
    printf("Address of %d is %p\n", *ptr, ptr);
    printf("Address of %d is %p\n", ptr->x, &ptr->x);
    printf("Address of %d is %p\n", p1, &p1);
    printf("Size = %lu", sizeof(struct Point));
    return 0;
}