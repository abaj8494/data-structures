typedef struct node *Node;

typedef Node Queue;

typedef int Item;

typedef struct node {
    Item item;
    Node next;
}node;

Queue createqueue(void);
void enqueue(Queue, Item);
Item dequeue(Queue);
void freequeue(Queue);




