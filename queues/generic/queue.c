#include <stdlib.h>
#include "queue.h"

Queue createQueue(void) {
    Queue q = malloc(sizeof(q));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void enQueue(Queue q, int item) {
    Node n = malloc(sizeof(n));
    n->data = item;
    n->next = NULL;

    if (q->tail == NULL) {
        // Queue is empty
        q->head = n;
        q->tail = n;
    } else {
        q->tail->next = n;
        q->tail = n;
    }
    q->size++;
}

int deQueue(Queue q) {
    int r = q->head->data;
    Node temp = q->head;
    q->head = q->head->next;
    free(temp);
    q->size--;
    return r;
}

void freeQueue(Queue q) {
    while (q->head != NULL) {
        Node curr = q->head;
        q->head = q->head->next;
        free(curr);
    }
    // free(q);
}

int Queuesize(Queue q) {return q->size;}
