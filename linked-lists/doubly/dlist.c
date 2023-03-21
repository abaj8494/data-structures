#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dlist.h"



int main(void) {
    Node n1 = create_node(1);
    Node n2 = create_node(2);
    Node n3 = create_node(3);
    insert_before(n1, n2);
    insert_after(n3, n2);
    print_list(n1);
    remove_node(n2);
    print_list(n1);
}

Node create_node(int data)
{
    Node n = malloc(sizeof(node));
    assert(n != NULL);
    n->prev = n->next = NULL;
    n->data = data;
    return n;
}

void insert_before(Node a, Node b)
{
    b->prev = a;
    a->next = b;
}

void insert_after(Node a, Node b)
{
    b->next = a;
    a->prev = b;
}

void print_list(Node head) 
{
    Node curr = head;

    while (curr != NULL) {
        printf("%d->", curr->data);
        curr = curr->next;
    }
    printf("X\n");
}

void remove_node(Node d)
{
    d->prev->next = d->next;
    free(d);
}
