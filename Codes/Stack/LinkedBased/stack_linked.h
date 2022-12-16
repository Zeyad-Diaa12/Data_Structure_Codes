#ifndef STACK_LINKED_H_INCLUDED
#define STACK_LINKED_H_INCLUDED

typedef int StackEntry;

typedef struct node{
    StackEntry info;
    struct node *next;
}Node;

typedef struct stack{
    int size;
    Node *head;
}Stack;

void CreateStack(Stack *s);
int isStackEmpty(Stack *s);
int isStackFull(Stack *s);
void Push(Stack *s,StackEntry item);
void Pop(Stack *s,StackEntry *item);
void ClearStack(Stack *s);
void TraverseStack(Stack *s,void(*pf)(StackEntry));
StackEntry FirstElementInStack(Stack *s);
StackEntry Peek(Stack *s);

#endif // STACK_LINKED_H_INCLUDED
