#include <stdio.h>
#include <string.h>
 
struct student_info
{
    char name[60];
    char surname[60];
    char sex[10];
    int age;
    unsigned int id;
    double gpa;
};
 
int main()
{
    struct student_info s1;
    scanf("%s %s %s %d %u %lf", s1.name, s1.surname, s1.sex, &s1.age, &s1.id, &s1.gpa);
 
    char title[5];
    if (strcmp(s1.sex, "Male") == 0)
        strcpy(title, "Mr");
    else if (strcmp(s1.sex, "Female") == 0)
        strcpy(title, "Miss");
    printf("%s %c %s (%d) ID: %08u GPA %.2lf", title, s1.name[0], s1.surname, s1.age, s1.id, s1.gpa);
}