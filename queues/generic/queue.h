// todo offer a generic itemtype typedef

typedef struct node* Node;

typedef struct node {
    int data;
    Node next;
} node;

typedef struct queue *Queue;

typedef struct queue {
    Node head;
    Node tail;
    int size;
} queue;


Queue createQueue(void);
void freeQueue(Queue);
void enQueue(Queue, int);
int deQueue(Queue);
int Queuesize(Queue);

