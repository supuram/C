/* 
In C programming, typedef struct is a way to create a new type that is based on a structure (struct) definition. It allows you to define a more convenient name (an alias) for a struct type, making your code more readable and abstract.
*/

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char name[50];
    int age;
    Date birthdate;
} Person;

int main() {
    Person person1;
    person1.age = 30;
    person1.birthdate.day = 15;
    person1.birthdate.month = 8;
    person1.birthdate.year = 1993;

    return 0;
}