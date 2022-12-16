#ifndef QUEUE_LINKED_H_INCLUDED
#define QUEUE_LINKED_H_INCLUDED

typedef int QueueEntry;

typedef struct node{
    QueueEntry info;
    struct node *next;
}Node;

typedef struct queue{
    Node *front;
    Node *rear;
    int size;
}Queue;

void CreateQueue(Queue *q);
int isQueueEmpty(Queue *q);
int isQueueFull(Queue *q);
void Enqueue(Queue *q,QueueEntry item);
void Dequeue(Queue *q,QueueEntry *item);
void ClearQueue(Queue *q);
void TraverseQueue(Queue *q,void(*pf)(QueueEntry));
int QueueSize(Queue *q);
QueueEntry FirstInQueue(Queue *q);
QueueEntry LastInQueue(Queue *q);

#endif // QUEUE_LINKED_H_INCLUDED
