#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node* Node;

Node create_node(int data);
Node create_list(int length);
void print_list(Node list);

int main(void)
{
    Node list1 = create_list(7);
    print_list(list1);

    return 0;
}

Node create_node(int data){
    Node new = malloc(sizeof(struct node));
    assert(new != NULL);
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


void print_list(Node list){
    Node curr = list;

    while (curr != NULL) {
        printf("%d->", curr->data);
        curr = curr->next;
    }

    printf("X\n");
}

