#include <stdio.h>
#include <stdlib.h>
#include "stack_array.h"



void CreateStack(Stack *s){
    s->top = 0;
}

int StackSize(Stack *s){
    return (s->top);
}

int isStackEmpty(Stack *s){
    return !s->top;
}

int isStackFull(Stack *s){
    return s->top==MAX;
}

void Push(Stack *s,StackEntry item){
    s->entry[s->top++]=item;
}

void Pop(Stack *s,StackEntry *item){
    *item=s->entry[--s->top];
}

void ClearStack(Stack *s){
    s->top=0;
}

StackEntry FirstElementInStack(Stack *s){
    return s->entry[0];
}

StackEntry Peek(Stack *s){
    return s->entry[s->top-1];
}

void CopyStack(Stack *s1,Stack *s2)
{
    for(int i=0;i<MAX;i++){
        s2->entry[s2->top++]=s1->entry[i];
    }
}

void TraverseStack(Stack *s,void(*pf)(StackEntry)){
    for(int i=0;i<StackSize(s);i++){
        (*pf)(s->entry[i]);
    }
}
