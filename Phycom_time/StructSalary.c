#include <stdio.h>
#include <string.h>
 
struct Record
{
    char id[10];
    char name[100];
    long salary;
    long sales;
};
 
int main()
{
    int n;
    if (scanf("%d", &n) != 1)
        return 0;
 
    struct Record employees[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s %ld %ld", employees[i].id, employees[i].name, &employees[i].salary, &employees[i].sales);
    }
 
    char search_id[10];
    scanf("%s", search_id);
 
    int found_index = -1;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(employees[i].id, search_id) == 0)
        {
            found_index = i;
            break;
        }
    }
 
    if (found_index == -1)
    {
        printf("ID not found !!!\n");
    }
    else
    {
        struct Record emp = employees[found_index];
        double commission = emp.sales * 0.02;
        double total_income = emp.salary + commission;
 
        printf("%s\n", emp.id);
        printf("%s\n", emp.name);
        printf("%ld\n", emp.sales);
        printf("%.2f\n", commission);
        printf("%ld\n", emp.salary);
        printf("%.2f\n", total_income);
    }
 
    return 0;
}