#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "BSTree.h"
#include "BSTProperty.h"

/* Count number of nodes in Tree */
Item TreeNumNodes(Tree t) {
    if (t == NULL) {
        return 0;
    } else {
        return 1 + TreeNumNodes(left(t)) + TreeNumNodes(right(t));
    }
}

/* Get the height of a tree */
int TreeHeight(Tree t) {
    if (t == NULL)
        return -1;
    else {
        int l = TreeHeight(t->left);
        int r = TreeHeight(t->right);
        return 1 + (l > r ? l : r);
    }
}

/* Get the smallest element of tree */
Tree BSTreeGetSmallest(Tree t) {
    if (t == NULL)
        return NULL;
    else if (t->left == NULL)
        return t;
    else
        return BSTreeGetSmallest(t->left);
}

/* Get the height of a specific node in tree */
int BSTreeNodeHeight(Tree t, int key) {
    if (t == NULL)
        return -1;
    else if (key == data(t))
        return 0;
    else if (key < data(t)) {
        int depth = BSTreeNodeHeight(t->left, key);
        return (depth == -1 ? -1 : depth + 1);
    } else {
        int depth = BSTreeNodeHeight(t->right, key);
        return (depth == -1 ? -1 : depth + 1);
    }
}

// Counts the number of leaves in the given BSTree
int BSTreeNumLeaves(BSTree t) {
	if (t == NULL) {
		return 0;
	} else if (t->left == NULL && t->right == NULL) {
		return 1;
	}
	return BSTreeNumLeaves(t->left) + BSTreeNumLeaves(t->right);
}