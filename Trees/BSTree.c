#include <stdlib.h>
#include <stdio.h>

#include "BSTree.h"

#define data(node) ((node)->data)
#define left(node) ((node)->left)
#define right(node) ((node)->right)

typedef struct Node {
    int data;
    Tree left;
    Tree right;
} Node;

Tree TreeCreate(Item it) {
    Tree root = malloc(sizeof(struct Node));
    data(root) = it;
    left(root) = NULL;
    root->right = NULL;
    return root;
}

void TreeFree(Tree t) {
    if (t != NULL) {
        TreeFree(t->left);
        free(t);
        TreeFree(t->right);
    }
    return;
}

Tree TreeInsert(Tree t, Item it) {
    if (t == NULL) {
        return TreeCreate(it);
    } else if (it < data(t)) {
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
    if (t != NULL) {
        printf("%d\n", t->data);
        showTree(t->left);
        showTree(t->right);
    }
}

/* Inorder BST Traversal */
void showTreeIn(Tree t, int depth) {
    if (t != NULL) {
        showTreeIn(t->right, depth + 1);
        for (int i = 0; i < depth; i++) {
            printf("  ");
        }
        printf("%d\n", t->data);
        showTreeIn(t->left, depth + 1);
    }
}

/* Preorder BST Traversal */
void showTreePre(Tree t, int depth) {
    if (t != NULL) {
        for (int i = 0; i < depth; i++) {
            printf("  ");
        }
        printf("%d\n", t->data);
        showTreePre(t->left, depth + 1);
        showTreePre(t->right, depth + 1);
    }
}

/* Postorder BST Traversal */
void showTreePost(Tree t, int depth) {
    if (t != NULL) {
        showTreePost(t->left, depth + 1);
        showTreePost(t->right, depth + 1);
        for (int i = 0; i < depth; i++) {
            printf("  ");
        }
        printf("%d\n", t->data);
    }
}