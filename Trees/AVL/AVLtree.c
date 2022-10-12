#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "AVLtree.h"


int height(Tree t) {
    if (t == NULL) {
        return 0;
    }
    return 1 + max(height(t->left), height(t->right));
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Tree TreeCreate(Item it) {
    Tree root = malloc(sizeof(struct Node));
    data(root) = it;
    left(root) = NULL;
    right(root) = NULL;
    root->height = 0;
    return root;
}

Tree rightRotate(Tree y) {
    Tree x = y->left;
    Tree T2 = x->right;

    // Perform right rotation
    x->right = y;
    y->left = T2;

    // Update Heights
    y->height = height(y);
    x->height = height(x);

    // Return new root
    return x;
}

Tree leftRotate(Tree x) {
    Tree y = x->right;
    Tree T2 = y->left;

    // Perform left rotation
    y->left = x;
    x->right = T2;

    // Update Heights
    x->height = height(x);
    y->height = height(y);

    // Return new root
    return y;
}

int getBalance(Tree t) {
    // If tree is empty, return height 0
    if (t == NULL) {
        return 0;
    }
    // Return the difference of Left and Right
    return height(t->left) - height(t->right);
}

Tree insertAVL(Tree t, Item it) {
    /* 1. Perform the normal BST insertion */
    if (t == NULL) 
        return (TreeCreate(it));

    if (it < t->data) // Searching through left
        t->left = insertAVL(t->left, it);
    else if (it > t->data) // Searching through right
        t->right = insertAVL(t->right, it);
    else // Data already existing, tree is just returned
        return t;

    /* 2. Update height of this ancestor node */
    t->height = height(t);

    /* 3. Get the balance factor of this ancestor
          node to check whether this node is unbalanced. 
          balance = difference in height of left and right */
    int balance = getBalance(t);

    /* 4. If tree node is unbalanced, then there are 4 cases */

    // Left Left Case
    // Left subtree is bigger than right subtree by 1
    if (balance > 1 && it < t->left->data)
        return rightRotate(t);

    // Right Right Case
    // Right subtree is bigger than left subtree by 1
    if (balance < -1 && it > t->right->data)
        return leftRotate(t);

    // Left Right Case
    // Left subtree is bigger by 1
    // Double rotate...
    if (balance > 1 && it > t->left->data) {
        t->left = leftRotate(t->left);
        return rightRotate(t);
    }
    
    // Right Left Case
    // Right subtree is bigger by 1
    if (balance < -1 && it < t->right->data) {
        t->right = rightRotate(t->right);
        return leftRotate(t);
    }

    return t;
}