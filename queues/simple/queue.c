#include "queue.h"
#include <stdlib.h>


Queue createqueue(void)
{
    Queue q = malloc(sizeof(q));
    q->next = NULL;
    return q;
}

void enqueue(Queue q, Item i) {
    Node curr = q;
    while (curr->next != NULL) curr = curr->next;
    Node new = malloc(sizeof(new));
    new->item = i;
    new->next = NULL;
    curr->next = new;
}


Item dequeue(Queue q)
{
    Node temp = q;
    Item r = temp->item;
    q = q->next;
    free(temp);
    return r;
}

void freequeue(Queue q)
{
    Node curr = q;
    while (curr != NULL) {
        Node temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(q);
}
