#ifndef STACK_ARRAY_H_INCLUDED
#define STACK_ARRAY_H_INCLUDED
#define MAX 10

typedef int StackEntry;

typedef struct stack{
    int top;
    StackEntry entry[MAX];
}Stack;



void CreateStack(Stack *s);
int isStackEmpty(Stack *s);
int isStackFull(Stack *s);
void Push(Stack *s,StackEntry item);
void Pop(Stack *s,StackEntry *item);
void ClearStack(Stack *s);
void CopyStack(Stack *s1,Stack *s2);
void TraverseStack(Stack *s,void(*pf)(StackEntry));
StackEntry FirstElementInStack(Stack *s);
StackEntry Peek(Stack *s);

#endif // STACK_ARRAY_H_INCLUDED
