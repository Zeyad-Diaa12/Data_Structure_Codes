#include <stdio.h>
#include <stdlib.h>
#include "queue_linked.h"

void CreateQueue(Queue *q){
    q->front=NULL;
    q->rear=NULL;
    q->size=0;
}

int isQueueEmpty(Queue *q){
    return !q->size;
}

int isQueueFull(Queue *q){
    return 0;
}

int QueueSize(Queue *q){
    return q->size;
}

void Enqueue(Queue *q,QueueEntry item){
    Node *pn=(Node*)malloc(sizeof(Node));
    pn->info=item;
    pn->next=NULL;
    if(!q->front){
        q->front=pn;
    }
    else{
        q->rear->next=pn;
    }
    q->rear=pn;
    q->size++;
}

void Dequeue(Queue *q,QueueEntry *item){
    *item = q->front->info;
    Node *pn;
    pn=q->front->next;
    free(q->front);
    q->front=pn;
    if(!q->front){
        q->rear=NULL;
    }
    q->size--;

}

void ClearQueue(Queue *q){
    Node *pn;
    pn=q->front;
    while(pn){
        q->front=pn->next;
        free(pn);
        pn=q->front;
    }
    q->rear=NULL;
    q->size=0;
}

QueueEntry FirstInQueue(Queue *q){
    return q->front->info;
}

QueueEntry LastInQueue(Queue *q){
    return q->rear->info;
}

void TraverseQueue(Queue *q,void(*pf)(QueueEntry)){
    Node *pn;
    pn=q->front;
    while(pn){
        (*pf)(pn->info);
        pn=pn->next;
    }
}


