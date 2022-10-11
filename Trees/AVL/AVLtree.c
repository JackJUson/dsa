#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "AVLtree.h"

Tree insertAVL(Tree t, Item it) {
    /* 1. Perform the normal BST insertion */
    if (t == NULL) 
        return (newNode(it));

    if (it < t->data) // Searching through left
        t->left = insertAVL(t->left, it);
    else if (it > t->data) // Searching through right
        t->right = insertAVL(t->right, it);
    else // Data already existing, tree is just returned
        return t;

    /* 2. Update height of this ancestor node */
    t->height = updateHeight(t);

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
    
    if (balance < -1 && it < t->right->data) {
        t->right = rightRotate(t->right);
        return leftRotate(t);
    }

    return t;
}