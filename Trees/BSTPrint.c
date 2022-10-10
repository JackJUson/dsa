#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "BSTree.h"
#include "BSTPrint.h"
#include "Queue.h"

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

// Prints the level-order traversal of the given BSTree
// Queue.h library required for helper functions
void BSTreeLevelOrder(BSTree t) {
	Queue q = QueueNew();
	QueueEnqueue(q, t->value);
	while (q != NULL) {
		QueueDequeue(q);
		for (Node curr = q->head; curr != NULL; curr = curr->next) {
			fprintf(fp, "%p ", curr->item);
		}
		QueueEnqueue(q, t->left->value);
		QueueEnqueue(q, t->right->value);
	}
}