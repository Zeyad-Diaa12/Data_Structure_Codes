#include <stdio.h>
#include <stdlib.h>
#include "queue_array.h"

void CreateQueue(Queue *q){
    q->front=0;
    q->rear=-1;
    q->size=0;
}

int isQueueEmpty(Queue *q){
    return !q->size;
}

int isQueueFull(Queue *q){
    return (q->size==MAX);
}

int QueueSize(Queue *q){
    return q->size;
}

void Enqueue(Queue *q,QueueEntry item){
    q->rear=(q->rear+1)%MAX;
    q->entry[q->rear]=item;
    q->size++;
}

void Dequeue(Queue *q,QueueEntry *item){
    *item=q->entry[q->front];
    q->front=(q->front+1)%MAX;
    q->size--;
}

void ClearQueue(Queue *q){
    q->front=0;
    q->rear=-1;
    q->size=0;
}

QueueEntry FirstInQueue(Queue *q){
    return q->entry[q->front];
}

QueueEntry LastInQueue(Queue *q){
    return q->entry[q->rear];
}

void TraverseQueue(Queue *q,void(*pf)(QueueEntry)){
    int pos,i;
    for(pos=q->front, i=0;i<q->size;i++){
        (*pf)(q->entry[pos]);
        pos = (pos+1)%MAX;
    }
}


