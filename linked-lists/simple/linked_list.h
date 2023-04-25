#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node* Node;

Node create_node(int data);
Node create_list(int length);
void print_list(Node list);
Node rec_reverseList(Node head);
Node reverseList(Node head);
