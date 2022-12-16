#ifndef QUEUE_ARRAY_H_INCLUDED
#define QUEUE_ARRAY_H_INCLUDED
#define MAX 10

typedef int QueueEntry;

typedef struct queue{
    int front;
    int rear;
    int size;
    QueueEntry entry[MAX];
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
#endif // QUEUE_ARRAY_H_INCLUDED
