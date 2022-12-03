#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "BSTree.h"
#include "BSTPrint.h"

Tree TreeCreate(Item it) {
    Tree t = malloc(sizeof(struct Node));
    if (t == NULL) {
		fprintf(stderr, "Insufficient memory!\n");
		exit(EXIT_FAILURE);
	}
    data(t) = it;
    left(t) = NULL;
    right(t) = NULL;
    return t;
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
Tree TreeDelete(Tree t, Item it) {
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

