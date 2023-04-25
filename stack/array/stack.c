#include "stack.h"
#include <stdlib.h>

Stack createStack(void) {
    Stack s = malloc(sizeof(stack));
    s->top = 0;
    return s;
}

void freeStack(Stack s) {
    free(s);
}

void push(Stack s, Item item) {
    if (s->top == MAX_STACK_SIZE) return;
    s->data[s->top] = item;
    s->top++;
}

Item pop(Stack s) {
    if (s->top <= 0) exit(1);
    s->top--;
    return s->data[s->top];
}

Item top(Stack s) {
    return s->data[s->top -1];
}

int sizeStack(Stack s) {
    return s->top;
}
