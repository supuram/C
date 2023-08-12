// Define an enum named DaysOfWeek to represent the days of the week (Sunday, Monday, Tuesday, etc.). Write a program that takes an integer input (1 to 7) from the user and prints the corresponding day of the week.

#include <stdio.h>

enum DaysOfWeek {
    Sunday = 1, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday
};

int main() {
    int dayNumber;
    printf("Enter a day number (1-7): ");
    scanf("%d", &dayNumber);

    if (dayNumber >= Sunday && dayNumber <= Saturday) {
        enum DaysOfWeek day = dayNumber;
        switch (day) {
            case Sunday:
                printf("Sunday\n");
                break;
            case Monday:
                printf("Monday\n");
                break;
            case Tuesday:
                printf("Tuesday\n");
                break;
            case Wednesday:
                printf("Wednesday\n");
                break;
            case Thursday:
                printf("Thursday\n");
                break;
            case Friday:
                printf("Friday\n");
                break;
            case Saturday:
                printf("Saturday\n");
                break;
            default:
                printf("Invalid day\n");
        }
    } else {
        printf("Invalid input\n");
    }

    return 0;
}