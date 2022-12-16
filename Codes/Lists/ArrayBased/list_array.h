#ifndef LIST_ARRAY_H_INCLUDED
#define LIST_ARRAY_H_INCLUDED
#define MAX 10

typedef int ListEntry;

typedef struct list{
    int size;
    ListEntry entry[MAX];
}List;

void CreateList(List *l);
int isListEmpty(List *l);
int isListFull(List *l);
int ListSize(List *l);
void ClearList(List *l);
void Insert(int pos,List *l,ListEntry item);
void Delete(int pos,List *l,ListEntry *item);
void TraverseList(List *l,void(*pf)(ListEntry));
void Replace(int pos,List *l,ListEntry item);
ListEntry GetAtIndex(List *l,int index);

#endif // LIST_ARRAY_H_INCLUDED
