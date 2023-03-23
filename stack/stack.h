typedef struct node* Stack;

typedef struct node *Node;

typedef struct node {
    int data;
    Node next;
} node;

Stack stackinit(void);
void push(Stack, int);
int pop(Stack);
void stackdestroy(Stack);
