#include <stdio.h>
#include <string.h>

struct man
{
    char firstName[20];
    char secondName[20];
    unsigned int age;
};

int main()
{
    man person;

    strcpy(person.firstName, "Ivan");
    strcpy(person.secondName, "Ivanov");
    person.age = 50;

    printf("Name = %s\n", person.firstName);
    printf("Name = %s\n", person.secondName);
    printf("Age = %u\n", person.age);
    printf("Sizeof(person) = %ld\n", sizeof(person));

    man* personPointer = &person;
    printf("*(...) first name = %s\n", (*personPointer).firstName);
    printf("-> first name = %s\n", personPointer->firstName);
    printf("Input second name and age: \n");
    int code = scanf("%s%u", personPointer->secondName, &(personPointer->age));
    if (code != 2)
    {
        printf("Input error!\n");
        return 1;
    }
    printf("Second name = %s, age = %u\n", personPointer->secondName, personPointer->age);
    return 0;
}