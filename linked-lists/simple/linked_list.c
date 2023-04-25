#include "linked_list.h"

// the node data structure
struct node {
    int data;
    struct node *next;
};


Node create_node(int data){
    Node new = malloc(sizeof(struct node));
    assert(new != NULL); // memory check
    new->data = data;
    new->next = NULL;
    return new;
}

Node create_list(int length) {
    Node head = NULL;
    if (length > 0) {
        head = create_node(0);
        int i = 1;
        Node curr = head;
        while (i < length) {
            curr->next = create_node(i);
            curr = curr->next;
            i++;
        }
    }
    return head;
}

Node rec_reverseList(Node head){
    if (head == NULL || head->next == NULL) {
        return head;
    }

    //reverse rest of list
    Node new_head = rec_reverseList(head->next);
    head->next->next = head;
    head->next = NULL;

    return new_head;
}

Node reverseList(Node head) {
    if (head == NULL) {
        return NULL;
    }
    struct node *previous = NULL;
    struct node *x = head;
    while (x != NULL) {
        Node y = x->next;
        x->next = previous;
        previous = x;
        x = y;
    }
    return previous;
}


void print_list(Node list){
    Node curr = list;

    while (curr != NULL) {
        printf("%d->", curr->data);
        curr = curr->next;
    }

    printf("X\n");
}


