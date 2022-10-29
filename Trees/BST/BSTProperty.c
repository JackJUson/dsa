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
        return 0;
    else if (t->left == NULL && t->right == NULL) {
        return 0;
    } else {
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
int BSTreeNumLeaves(Tree t) {
	if (t == NULL) {
		return 0;
	} else if (t->left == NULL && t->right == NULL) {
		return 1;
	}
	return BSTreeNumLeaves(t->left) + BSTreeNumLeaves(t->right);
}

// Deletes all of the leaves in the given BSTree and returns the root of
// the updated BSTree
Tree BSTreeDeleteLeaves(Tree t) {
	if (t == NULL) {
		return NULL;
	} else if (t->left == NULL && t->right == NULL) {
		free(t);
		return NULL;
	}
	t->left = BSTreeDeleteLeaves(t->left);
	t->right = BSTreeDeleteLeaves(t->right);
	return t;
}

/* Counts the odd values in the tree */
int BSTreeCountOdds(Tree t) {
    if (t == NULL) {
        return 0;
    } else if (t->data % 2 != 0) {
        return 1 + BSTreeCountOdds(t->left) + BSTreeCountOdds(t->right);
    } else {
        return BSTreeCountOdds(t->left) + BSTreeCountOdds(t->right)
    }
}

/* Counts the internal node of a tree (Internal node = node with least one subtree)*/
int BSTreeCountInternal(Tree t) {
    if (t == NULL) {
        return 0;
    } else if (t->left == NULL && t->right == NULL) {
        return 0;
    } else {
        int l = BSTreeCountInternal(t->left);
        int r = BSTreeCountInternal(t->right);
        return 1 + l + r;
    }
}

/* Counts values that are greater than the given val */
int BSTreeCountGreater(BSTree t, int val) {
    if (t == NULL) {
        return 0;
    } else if (t->data > val) {
        return 1 + BSTreeCountGreater(t->right, val) + BSTreeCountGreater(t->left, val);
    } else {
        return BSTreeCountGreater(t->right, val);
    }
}
