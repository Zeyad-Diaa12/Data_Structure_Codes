#include <stdio.h>
#include <stdlib.h>
#include "list_linked.h"

void CreateList(List *l){
    l->head=NULL;
    l->size=0;
}

int isListEmpty(List *l){
    return !l->size;
}

int isListFull(List *l){
    return 0;
}

int ListSize(List *l){
    return l->size;
}

void Insert(int pos,List *l,ListEntry item){
    Node *pn=(Node*)malloc(sizeof(Node));
    pn->info=item;
    pn->next=NULL;

    if(pos == 0){
        pn->next=l->head;
        l->head=pn;
    }
    else{
        Node *t;
        t=l->head;
        int i=0;
        while(t->next && i<pos-1){
            t=t->next;
            i++;
        }
        pn->next=t->next;
        t->next=pn;
    }
    l->size++;
}

void Delete(int pos,List *l,ListEntry *item){
    Node *pn;
    pn=l->head;

    if(pos == 0){
        l->head=l->head->next;
    }
    else{
        Node *t;
        t=l->head;
        int i =0;
        while(t->next && i<pos-1){
            t=t->next;
            i++;
        }
        pn=t->next;
        t->next=t->next->next;
    }
    *item = pn->info;
    free(pn);
    l->size--;
}

void Replace(int pos,List *l,ListEntry item){
    Node *pn;
    pn=l->head;

    if(pos == 0){
        pn->info=item;
    }
    else{
        int i =0;
        while(pn->next && i<pos){
            pn=pn->next;
            i++;
        }
        pn->info=item;
    }
}

ListEntry GetAtIndex(List *l,int index){
    Node *pn;
    pn=l->head;

    if(index == 0){
        return pn->info;
    }
    else{
        int i =0;
        while(pn->next && i<index){
            pn=pn->next;
            i++;
        }
        return pn->info;
    }
}

void ClearList(List *l){
    Node *pn;
    pn=l->head;

    while(pn){
        l->head=pn->next;
        free(pn);
        pn=l->head;
    }
    l->size=0;
}

void TraverseList(List *l,void(*pf)(ListEntry)){
    Node *pn;
    pn = l->head;

    while(pn){
        (*pf)(pn->info);
        pn=pn->next;
    }
}

