#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "btree.h"

struct treeNode {
    TreeItem item;
    treelink left;
    treelink right;
};

static treelink createNode(TreeItem item) {
    treelink t = (treelink) malloc (sizeof (*t));
    t->item = item;
    t->left = NULL;
    t->right = NULL;
    return t;
}


// inserts duplicates on the left
treelink insertTreeNode (treelink tree, TreeItem item) {
    if (tree == NULL) {
        tree = createNode(item);
        tree->item = item;
        tree->left = NULL;
        tree->right = NULL;
    }
    else if (tree->item < item) {
        tree->right = insertTreeNode (tree->right, item);
    } else {
        tree->left = insertTreeNode (tree->left, item);
    }
    return tree;
}
