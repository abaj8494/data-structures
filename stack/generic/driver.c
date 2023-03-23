#include <stdio.h>
#include "Stack.h"

int main(void)
{
    Stack s = StackNew();
    StackPush(s, 50);
    StackPush(s, 60);
    StackPush(s, 70);
    StackPush(s, 80);
    StackPush(s, 90);
    StackDump(s, stdout);
    for (int i = 0; i < 5; i++) printf("popped: %d\n", StackPop(s));
    StackFree(s);
}
