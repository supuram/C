// *! Just like lib_ccx.c , line 149

#include<stdio.h>
#include<stdlib.h>

struct Point1{
    int x1;
    int y1;
};

struct Point2{
    int x2;
    int y2;
    struct Point1 *pt1;
};

struct Point3{
    int x3;
    int y3;
};

struct Point1 *ptFunc1(struct Point3 *pt3){
    struct Point1 *setting;
    setting = malloc(sizeof(struct Point1));
    setting->x1 = pt3->x3;
    setting->y1 = pt3->y3;

    return setting;
}

int main(){
    struct Point2 *pt2 = malloc(sizeof(struct Point2));
    struct Point3 *p3 = malloc(sizeof(struct Point3));

    pt2->x2 = 30;
    pt2->y2 = 40;
    p3->x3 = 10;
    p3->y3 = 20;
    
    pt2->pt1 = ptFunc1(p3);

    printf("Point1: x1 = %d, y1 = %d\n", pt2->pt1->x1, pt2->pt1->y1);
    printf("Point2: x2 = %d, y2 = %d, x1 in pt1 = %d\n", pt2->x2, pt2->y2, pt2->pt1->x1);
    printf("Point2: x2 = %p, y2 = %p, pt1 = %p\n", &pt2->x2, &pt2->y2, &pt2->pt1);

    // Free dynamically allocated memory
    free(pt2->pt1);
    free(pt2);
    free(p3); // Free memory for Point3
    return 0;
}