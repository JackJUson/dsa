#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "BSTree.h"
#include "BSTBalance.h"
#include "BSTProperty.h"

/* Rotating tree to the right */
Tree rotateRight(Tree n1) {
    if (n1 == NULL || left(n1) == NULL)
        return n1;
    Tree n2 = left(n1);
    left(n1) = right(n2);
    right(n2) = n1;
    return n2;
}

/* Rotating tree to the left */
Tree rotateLeft(Tree n1) {
    if (n1 == NULL || right(n1) == NULL)
        return n1;
    Tree n2 = right(n1);
    right(n1) = left(n2);
    left(n2) = n1;
    return n2;
}

/* Inserting at the root */
/* And rotating the tree to make the new node the new root */
Tree insertAtRoot(Tree t, Item it) {
    Tree root = t;
    if (t == NULL) {
        t = TreeCreate(it);
    } else if (it < data(root)) {
        left(t) = insertAtRoot(left(t), it);
        t = rotateRight(t);
    } else if (it > data(root)) {
        right(t) = insertAtRoot(right(t), it);
        t = rotateLeft(t);
    }
    return t;
}

/* Partitioning Tree */
/* Rearranging tree to make node with index i becomes root */
/* Index of node are based on pre-order, smallest -> biggest */
Tree partition(Tree t, int index) {
    if (t != NULL) {
        assert(0 <= index && index < TreeNumNodes(t));
        int m = TreeNumNodes(left(t));
        if (index < m) {
            left(t) = partition(left(t), index);
            t = rotateRight(t);
        } else if (index > m) {
            right(t) = partition(right(t), index - m - 1);
            t = rotateLeft(t);
        }
    }
    return t;
}

/* Periodic Rebalancing */
/* Only rebalance tree after a certain amount of inputs/actions */
Tree rebalance(Tree t) {
    int n = TreeNumNodes(t);
    if (n >= 3) {
        t = partition(t, n/2);              // put node with median key at root
        left(t) = rebalance(left(t));       // then rebalance each subtree
        right(t) = rebalance(right(t));
    }
    return t;
}