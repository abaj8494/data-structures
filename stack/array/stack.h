#define MAX_STACK_SIZE 7

// this can be changed according to the implementation of your stack.
// I could even #include "item.h".
typedef int Item;

typedef struct stack *Stack;

typedef struct stack {
    Item data[MAX_STACK_SIZE];
    Item top;
} stack;

Stack createStack(void);
void freeStack(Stack);
void push(Stack, Item);
Item pop(Stack);
Item top(Stack);

int sizeStack(Stack);
