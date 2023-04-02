// linked list implementation of a binary tree
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

typedef struct node {
    Item item;
    Node left;
    Node right;
} node;

Node NodeCreate(Item item) {
    Node new = malloc(sizeof(new));
    new->item = item;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void TreePrint(Node n) {
    if (n == NULL) {printf("---\n"); return;}
    else {
        printf("value: %d\n", n->item);
        printf("left\n");
        TreePrint(n->left);
        printf("right\n");
        TreePrint(n->right);
    }
}

int main(void)
{
    Node n1 = NodeCreate(5);
    Node n2 = NodeCreate(6);
    Node n3 = NodeCreate(7);
    Node n4 = NodeCreate(8);
    Node n5 = NodeCreate(9);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    
    TreePrint(n1);

    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
}
