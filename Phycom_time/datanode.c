#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  
// DataNode structure using typedef
typedef struct DataNode
{
    char *data;
    struct DataNode *next;
} DataNode;
  
DataNode *createDataNode(char *data);
  
DataNode *createDataNode(char *data)
{
    DataNode *p = malloc(sizeof(DataNode));
    p->data = data;
    p->next = NULL;
    return p;
}
  
int main()
{
    char data[101];
    scanf("%[^\n]s", data);
  
    DataNode *pNew = createDataNode(data);
  
    printf("%s\n", pNew->data);
    printf("%p\n", (void *)pNew->next);
  
    return 0;
}