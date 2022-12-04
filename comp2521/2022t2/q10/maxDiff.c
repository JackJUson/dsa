
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "BSTree.h"

int TreeNumNodes(BSTree t);
void doMaxDiff(BSTree t, int *max);

int maxDiff(BSTree t) {
    int max = 0;
    doMaxDiff(t, &max);

    return max;
}

// Preorder traversal and keep changing max if its bigger
void doMaxDiff(BSTree t, int *max) {
    if (t != NULL) {
        int diff = abs(TreeNumNodes(t->left) - TreeNumNodes(t->right));
        if (*max < diff) {
            *max = diff;
        }

        doMaxDiff(t->left, max);
        doMaxDiff(t->right, max);
    }
}


int TreeNumNodes(BSTree t) {
    if (t == NULL) {
        return 0;
    } else {
        return 1 + TreeNumNodes(t->left) + TreeNumNodes(t->right);
    }
}