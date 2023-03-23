#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

Stack stackinit(void)
{
    Stack s = malloc(sizeof(s));
    s->next = NULL;
    return s;
}

void push(Stack s, int d)
{
   Node n = malloc(sizeof(n));
   n->data = d;
   n->next = s;
   s = n;
}

int pop(Stack s)
{
    int d = s->data;

    Node temp = s;
    s = s->next;
    free(temp);
    return d;
}

void stackdestroy(Stack s)
{
    do {
        Node temp = s;
        s = s->next;
        free(temp);
    } while (s->next != NULL);
    free(s);
    
}

