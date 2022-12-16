#include <stdio.h>
#include <stdlib.h>
#include "stack_linked.h"


void CreateStack(Stack *s){
    s->head=NULL;
    s->size=0;
}

int StackSize(Stack *s){
    return (s->size);
}

int isStackEmpty(Stack *s){
    return !s->size;
}

int isStackFull(Stack *s){
    return 0;
}

void Push(Stack *s,StackEntry item){
    Node *pn=(Node*)malloc(sizeof(Node));
    pn->info =item;
    pn->next=s->head;
    s->head=pn;
    s->size++;
}

void Pop(Stack *s,StackEntry *item){
    Node *pn;
    *item=s->head->info;
    pn=s->head;
    s->head=pn->next;
    free(pn);
    s->size--;
}

void ClearStack(Stack *s){
    Node *pn=s->head;
    while(pn){
        s->head=pn->next;
        free(pn);
        pn=s->head;
    }
    s->size=0;
}

StackEntry FirstElementInStack(Stack *s){
    Node *pn = (Node*)malloc(sizeof(Node));
    pn=s->head;
    while(pn->next){
        pn=pn->next;
    }
    return pn->info;
}

StackEntry Peek(Stack *s){
    return s->head->info;
}

void TraverseStack(Stack *s,void(*pf)(StackEntry)){
    Node *pn=s->head;
    while(pn){
        (*pf)(pn->info);
        pn=pn->next;
    }
}
