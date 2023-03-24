#include <stdio.h>
#include "queue.h"

int main(void)
{
    Queue q = createqueue();
    enqueue(q, 5);
    enqueue(q, 6);
    enqueue(q, 7);
    enqueue(q, 8);
    for (int i = 0; i < 3; i++) printf("%d\n", dequeue(q));
    freequeue(q);
}
