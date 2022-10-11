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
          node to check whether this node is unbalanced */
    int balance = getBalance(t);

}