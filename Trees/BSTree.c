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
    return NULL;
}

void showTree(Tree t) {
}
