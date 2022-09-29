#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "BSTree.h"

/* Define tag for tree nodes */
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
    right(root) = NULL;
    return root;
}

void TreeFree(Tree t) {
    if (t != NULL) {
        TreeFree(left(t));
        TreeFree(right(t));
        free(t);
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

/* Count number of nodes in Tree */
Item TreeNumNodes(Tree t) {
    if (t == NULL) {
        return 0;
    } else {
        return 1 + TreeNumNodes(left(t)) + TreeNumNodes(right(t));
    }
}

/* Search item in a Tree */
bool TreeSearch(Tree t, Item it) {
    if (t == NULL) 
        return false;
    else if (it < data(t)) 
        return TreeSearch(left(t), it);
    else if (it > data(t)) 
        return TreeSearch(right(t), it);
    else  // it == data(t);
        return true;
}

/* Joins two Trees into one  */
Tree joinTrees(Tree t1, Tree t2) {
    if (t1 == NULL)
        return t1;
    else if (t2 == NULL)
        return t2;
    else {
        Tree current = t2;
        Tree parent = NULL;

        while(left(current) != NULL) {      // Find min element in t2
            parent = current;
            current = left(current);
        }
        if (parent != NULL) {
            left(parent) = right(current);  // Link the new left of parent to right node of current
            right(current) = t2;            // Current right as t2, current new root
        }
        left(current) = t1;                 // Current left as t1, current new root
        return current;                     // Return root of tree
    }
}

/* Delete a node from a Tree */
Tree TreeDelete(Tree t, Item t) {
    if (t != NULL) {
        if (it < data(t))
            left(t) = TreeDelete(left(t), it);
        else if (it > data(t))
            right(t) = TreeDelete(right(t), it);
        else {
            Tree new;
            if (left(t) == NULL && right(t) == NULL)
                new = NULL;
            else if (left(t) == NULL)
                new = right(t);
            else if (right(t) == NULL)
                new = left(t);
            else 
                new = joinTrees(left(t), right(t));
            free(t);
            t = new;
        }
    }
    return t;
}

/* Prints all elements of tree in List */
void showTree(Tree t) {
    if (t != NULL) {
        printf("%d\n", t->data);
        showTree(t->left);
        showTree(t->right);
    }
}

/* Inorder BST Traversal */
/* Closest looking tree sideways */
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