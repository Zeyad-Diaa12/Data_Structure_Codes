#ifndef LIST_LINKED_H_INCLUDED
#define LIST_LINKED_H_INCLUDED

typedef int ListEntry;

typedef struct node{
    ListEntry info;
    struct node *next;
}Node;

typedef struct list{
    int size;
    Node *head;
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

#endif // LIST_LINKED_H_INCLUDED
