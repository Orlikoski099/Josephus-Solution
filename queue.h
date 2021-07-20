#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct queue {
    int info;
    int pos;
    struct queue *prv;
    struct queue *next;
} Queue;

Queue* create_queue ();

void free_queue (Queue *q);

Queue* enqueue (Queue *q, int elem);

Queue* dequeue (Queue *q, int pos);

int front (Queue *q);

int empty_queue (Queue *q);

Queue* linkStartEnd(Queue *q);

int lastOne (Queue *q);

void winner (Queue *q);
