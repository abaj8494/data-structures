
typedef struct node *Node;
typedef struct node {
    int data;
    Node prev;
    Node next;
} node;


Node create_node(int data);
void remove_node(Node n);
void insert_before(Node a, Node b);
void insert_after(Node a, Node b);
void print_list(Node n);
