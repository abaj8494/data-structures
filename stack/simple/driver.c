#include <stdio.h>
#include "stack.h"

int main(void)
{
    Stack s = stackinit();
    push(s, 5);
    push(s, 2);
    push(s, 3);
    for (int i = 0, r; i < 3; i++) {r = pop(s); printf("popping off: %d\n", r);}
    stackdestroy(s);
    return 0;
}
