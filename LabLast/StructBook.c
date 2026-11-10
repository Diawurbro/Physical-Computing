#include <stdio.h>
#include <string.h>
 
struct Book
{
    char id[10];
    char name[100];
    char author[100];
};
 
int main()
{
    int n;
    scanf(" %d", &n);
    struct Book book[n];
    char searchId[10];
    scanf(" %s", searchId);
    struct Book selectBook;
    int found = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s %s", book[i].id, book[i].name, book[i].author);
        if (strcmp(book[i].id, searchId) == 0)
        {
            selectBook = book[i];
            found = 1;
        }
    }
    if (found == 0)
        printf("Not Found");
    else
    {
        printf("%s %s %s", selectBook.id, selectBook.name, selectBook.author);
    }
}