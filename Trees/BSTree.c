#include <stdlib.h>
#include <stdio.h>

#include "BSTree.h"

typedef struct Node {
    int data;
    Tree left;
    Tree right;
} Node;

Tree TreeCreate(Item it) {
    Tree root = malloc(sizeof(struct Node));
    root->data = it;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void TreeFree(Tree t) {
}

Tree TreeInsert(Tree t, Item it) {
    if (t == NULL) {
        return TreeCreate(it);
    } else if (it < t->data) {
        t->left = TreeInsert(t->left, it);
    } else if (it > t->data) {
        t->right = TreeInsert(t->right, it);
    }
    return t;
}

/*
TreeInsert(Tree, item):
    if Tree is empty:
        return new root node containing item
    else if item < Tree's value:
        Tree's left child = TreeInsert(Tree's left child , item)
    else if item > Tree's value:
        Tree's right child = TreeInsert(Tree's right child, item)
    else:
        return tree (avoid duplicates)
*/

void showTree(Tree t) {
}
