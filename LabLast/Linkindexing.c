#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// DataNode structure using typedef
typedef struct DataNode
{
    char *data;
    struct DataNode *next;
} DataNode;
typedef struct SinglyLinkedList
{
    unsigned int count;
    DataNode *head;
} SinglyLinkedList;
 
// Function prototypes
DataNode *createDataNode(char *data);
SinglyLinkedList *createSinglyLinkedList();
void traverse(SinglyLinkedList *list);
void insert_last(SinglyLinkedList *list, char *data);
void insert_front(SinglyLinkedList *list, char *data); // <-- สร้างตัวนี้
void delete(SinglyLinkedList *list, char *data);       // <-- สร้างตัวนี้
char *search_index(SinglyLinkedList *list, int index);
 
int main()
{
    SinglyLinkedList *mylist = createSinglyLinkedList();
    int n, index;
    while (1)
    {
        char *a = (char *)malloc(sizeof(char) * 21);
        scanf(" %[^\n]", a);
        if (strcmp(a, "Last") == 0)
        {
            free(a);
            break;
        }
        insert_last(mylist, a);
        free(a);
    }
    scanf("%d", &n);
    // 2 = -4 + count
    if (n < 0)
        index = n + mylist->count;
    else
        index = n;
    char *data = search_index(mylist, index);
    if (data == NULL)
        printf("Error");
    else
        printf("%s", data);
    // Remember to free allocated memory for each node's data
    DataNode *current = mylist->head;
    while (current != NULL)
    {
        free(current->data);
        DataNode *temp = current;
        current = current->next;
        free(temp);
    }
    free(mylist);
    return 0;
}
DataNode *createDataNode(char *data)
{
    DataNode *temp = malloc(sizeof(DataNode));
    temp->data = malloc(strlen(data) + 1);
    strcpy(temp->data, data);
    temp->next = NULL;
    return temp;
}
 
// Create a new SinglyLinkedList
SinglyLinkedList *createSinglyLinkedList()
{
    SinglyLinkedList *temp = malloc(sizeof(SinglyLinkedList));
    temp->count = 0;
    temp->head = NULL;
    return temp;
}
 
// Traverse the list and print data
void traverse(SinglyLinkedList *list)
{
    if (list->count == 0)
    {
        printf("This is an empty list.\n");
        return;
    }
    struct DataNode *pointer = list->head;
    while (pointer->next != NULL)
    {
        printf("%s -> ", pointer->data);
        pointer = pointer->next;
    }
    printf("%s\n", pointer->data);
}
 
char *search_index(SinglyLinkedList *list, int index)
{
    if (index < 0)
        return NULL;
    DataNode *current = list->head;
    for (int i = 0; i < index; i++)
    {
        if (current == NULL)
            return NULL;
        current = current->next;
    }
    if (current == NULL)
        return NULL;
    return current->data;
}
 
// Insert a new node at the end of the list
void insert_last(SinglyLinkedList *list, char *data)
{
    struct DataNode *pNew = createDataNode(data);
    if (list->count == 0)
    {
        list->head = pNew;
    }
    else
    {
        DataNode *pTemp = list->head;
        while (pTemp->next != NULL)
            pTemp = pTemp->next;
        pTemp->next = pNew;
    }
    list->count++;
}
 
void insert_front(SinglyLinkedList *list, char *data)
{
    struct DataNode *pNew = createDataNode(data);
    DataNode *temp = list->head;
    pNew->next = temp;
    list->head = pNew;
    list->count++;
}
void delete(struct SinglyLinkedList *list, char *data)
{
    struct DataNode *current = list->head;
    struct DataNode *previous = NULL;
 
    int found = 0;
    while (current != NULL && found == 0)
    {
        if (strcmp(current->data, data) == 0)
            found = 1;
        else
        {
            previous = current;
            current = current->next;
        }
    }
    if (found == 0)
    {
        printf("Cannot delete, %s does not exist.\n", data);
        return;
    }
    if (list->head == current)
    {
        list->head = current->next;
        // delete start
    }
    else if (current->next == NULL)
    {
        previous->next = NULL;
        // delete last
    }
    else
    {
        previous->next = current->next;
        // delete between
    }
 
    free(current->data);
    free(current);
 
    list->count--;
}