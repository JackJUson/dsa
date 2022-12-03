#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "BSTree.h"
#include "BSTProperty.h"

#define NOT_HEIGHT_BALANCED -99

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

/* Sum all the odd values in the tree */
int TreeSumOdds(Tree t) {
	if (t == NULL) {
		return 0;
	} else if (t->value % 2 != 0) {
		return t->value + TreeSumOdds(t->left) + TreeSumOdds(t->right);
	} else {
		return TreeSumOdds(t->left) + TreeSumOdds(t->right);
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
int BSTreeCountGreater(Tree t, int val) {
    if (t == NULL) {
        return 0;
    } else if (t->data > val) {
        return 1 + BSTreeCountGreater(t->right, val) + BSTreeCountGreater(t->left, val);
    } else {
        return BSTreeCountGreater(t->right, val);
    }
}

/* Checks if the tree or subtree is height balanced */
int isHeightBalanced(Tree t) {
    if (t == NULL) {
        return -1;
    }
    int hl = isHeightBalanced(t->left);
    int hr = isHeightBalanced(t->right);

    if (hl == -1 || hr == -1) {
        return NOT_HEIGHT_BALANCED;
    }

    int diff = hl - hr;
    if (diff < -1 || diff > 1) {
        return NOT_HEIGHT_BALANCED;
    }

    return (hl > hr ? hl : hr) + 1;
}

// Recursive height balance check function
bool TreeIsPerfectlyBalanced(Tree t) {
	if (t == NULL) {
		return true;
	}
	
	int l = TreeNumNodes(t->left);
	int r = TreeNumNodes(t->right);
	if (l - r > 1 || r - l > 1) {
		return false;
	} else {
		return TreeIsPerfectlyBalanced(t->left) &&
		       TreeIsPerfectlyBalanced(t->right);
	}
}

// Checks if tree is symmetric around its center
bool isSymmetric(struct TreeNode* root){
    if (root == NULL) {
        return true;
    }
    return isParallelCheck(root->left, root->right);
}
bool isParallelCheck(struct TreeNode *a, struct TreeNode *b) {
    if (a == NULL && b == NULL) {
        return true;
    }
    if (a == NULL || b == NULL) {
        return false;
    } 
    if (a->val != b->val) {
        return false;
    }
    return isParallelCheck(a->left, b->right) && isParallelCheck(a->right, b->left);
}

/* Get the kth smallest value in a tree (using array)*/
int BSTreeGetKth(BSTree t, int k) {
	int numN = TreeNumNodes(t);
	int *array = malloc(numN * sizeof(int));
	int index = 0;
	saveTreeToArray(t, array, &index);
	int save = array[k];
	free(array);
	return save;
}
void saveTreeToArray(BSTree t, int *array, int *index) {
    if (t != NULL) {
        saveTreeToArray(t->left, array, index);
		array[*index] = t->value;
		(*index)++;
        saveTreeToArray(t->right, array, index);
    }
}

// Get the kth smallest value in a tree
int BSTreeGetKth(BSTree t, int k) {
	int leftSize = BSTreeSize(t->left);
	if (k == leftSize) {
		return t->value;
	} else if (k < leftSize) {
		return BSTreeGetKth(t->left, k);
	} else {
		return BSTreeGetKth(t->right, k - leftSize - 1);
	}
}

// Copies a tree up to a given depth
Tree TreeCopy(Tree t, int depth) {
	if (t == NULL || depth < 0) {
		return NULL;
	}
	
	Tree copy = TreeCreate(t->value);
	copy->left = TreeCopy(t->left, depth - 1);
	copy->right = TreeCopy(t->right, depth - 1);
	return copy;
}