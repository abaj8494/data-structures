#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "btree.h"

int main (int argc, char *argv[])
{
    treelink t1 = insertTreeNode(NULL, 10);
    insertTreeNode(t1, 20);
    insertTreeNode(t1, 5);
    insertTreeNode(t1, 30);
    insertTreeNode(t1, 15);
    insertTreeNode(t1, 25);
    insertTreeNode(t1, 24);

    printf("We can test our tree here\n");

    return EXIT_SUCCESS;
}
