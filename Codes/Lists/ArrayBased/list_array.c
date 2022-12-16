#include <stdio.h>
#include <stdlib.h>
#include "list_array.h"

void CreateList(List *l){
    l->size=0;
}

int isListEmpty(List *l){
    return !l->size;
}

int isListFull(List *l){
    return (l->size==MAX);
}

int ListSize(List *l){
    return l->size;
}

void Insert(int pos,List *l,ListEntry item){
    for(int i=l->size-1;i>=pos;i--){
        l->entry[i+1]=l->entry[i];
    }
    l->entry[pos]=item;
    l->size++;
}

void Delete(int pos,List *l,ListEntry *item){
    *item = l->entry[pos];
    for(int i=pos;i<l->size-1;i++){
        l->entry[i]=l->entry[i+1];
    }
    l->size--;
}

void Replace(int pos,List *l,ListEntry item){
    l->entry[pos] = item;
}

ListEntry GetAtIndex(List *l,int index){
    return l->entry[index];
}

void ClearList(List *l){
    l->size=0;
}

void TraverseList(List *l,void(*pf)(ListEntry)){
    for(int i=0;i<l->size;i++){
        (*pf)(l->entry[i]);
    }
}

