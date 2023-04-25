#include <stdio.h>
#include "stack.h"

int main(void) {
    Stack fs = createStack();
    push(fs, 1);
    push(fs, 2);
    push(fs, 3);
    push(fs, 4);
    push(fs, 5);

    for (int i = 0; i < 5; i++) {
        printf("Person %d is cutting!\n", pop(fs));
    }

    push(fs, 1);
    push(fs, 3);
    push(fs, 4);

    printf("It looks like the person at the back of the stack is number %d\n", top(fs));
    printf("There are %d people in the stack!\n", sizeStack(fs));
}
