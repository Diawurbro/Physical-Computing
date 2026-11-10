#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
 
struct student_info
{
    char name[60];
    char surname[60];
    char sex[10];
    int age;
    char id[13];
    double gpa;
};
 
int my_strcasecmp(const char *s1, const char *s2)
{
    while (*s1 && *s2)
    {
        int diff = tolower((unsigned char)*s1) - tolower((unsigned char)*s2);
        if (diff != 0)
            return diff;
        s1++;
        s2++;
    }
    return tolower((unsigned char)*s1) - tolower((unsigned char)*s2);
}
 
int compare_name(const void *a, const void *b)
{
    struct student_info *s1 = (struct student_info *)a;
    struct student_info *s2 = (struct student_info *)b;
    return my_strcasecmp(s1->name, s2->name);
}
 
int compare_surname(const void *a, const void *b)
{
    struct student_info *s1 = (struct student_info *)a;
    struct student_info *s2 = (struct student_info *)b;
    return my_strcasecmp(s1->surname, s2->surname);
}
 
int compare_id(const void *a, const void *b)
{
    struct student_info *s1 = (struct student_info *)a;
    struct student_info *s2 = (struct student_info *)b;
    return strcmp(s1->id, s2->id);
}
 
int main()
{
    struct student_info students[20];
 
    for (int i = 0; i < 20; i++)
    {
        scanf("%s %s %s %d %s %lf",
              students[i].name,
              students[i].surname,
              students[i].sex,
              &students[i].age,
              students[i].id,
              &students[i].gpa);
    }
 
    char option[50];
    scanf("%s", option);
 
    if (my_strcasecmp(option, "name") == 0)
    {
        qsort(students, 20, sizeof(struct student_info), compare_name);
    }
    else if (my_strcasecmp(option, "surname") == 0)
    {
        qsort(students, 20, sizeof(struct student_info), compare_surname);
    }
    else if (my_strcasecmp(option, "id") == 0)
    {
        qsort(students, 20, sizeof(struct student_info), compare_id);
    }
 
    for (int i = 0; i < 20; i++)
    {
        const char *title = (strcmp(students[i].sex, "Male") == 0) ? "Mr" : "Miss";
        printf("%s %c %s (%d) ID: %s GPA %.2lf\n",
               title,
               students[i].name[0],
               students[i].surname,
               students[i].age,
               students[i].id,
               students[i].gpa);
    }
 
    return 0;
}