#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

int main(void)
{
    Queue cq = createQueue();
    for (int i = 1; i <= 10; i++) {
        printf("Person %d in Queue.\n",i);
        enQueue(cq, i);
    }
    for (int i = 1; i <= 10; i++) {
        printf("Person %d entered the store.\n", deQueue(cq));
    }
}
