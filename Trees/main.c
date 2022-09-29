// Binary Search Tree ADT Tester ... 

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "BSTree.h"

int main(int argc, char *argv[]) {
    Tree t = TreeCreate(4);
    t = TreeInsert(t, 2);
    t = TreeInsert(t, 6);
    t = TreeInsert(t, 5);
    t = TreeInsert(t, 1);
    t = TreeInsert(t, 7);
    t = TreeInsert(t, 10);
    t = TreeInsert(t, 9);
    t = TreeInsert(t, 8);

    /* List style print */
    showTree(t);

    /* Inorder style print */
    showTreeIn(t, 0);

    printf("Number of nodes in Tree: %d\n", TreeNumNodes(t));

    if (TreeSearch(t, 3)) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    if (TreeSearch(t, 10)) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }
    TreeFree(t);

    printf("\n");

    Tree t1 = TreeCreate(10);
    t1 = TreeInsert(t1, 5);
    t1 = TreeInsert(t1, 14);

    printf("t1 Tree:\n");
    showTreeIn(t1, 0);
    printf("\n");

    Tree t2 = TreeCreate(30);
    t2 = TreeInsert(t2, 24);
    t2 = TreeInsert(t2, 32);
    t2 = TreeInsert(t2, 29);

    printf("t2 Tree:\n");
    showTreeIn(t2, 0);
    printf("\n");

    t1 = joinTrees(t1, t2);

    printf("Combined Tree:\n");
    showTreeIn(t1, 0);

    t1 = TreeDelete(t1, 30);

    printf("Delete 30 from Tree:\n");
    showTreeIn(t1, 0);

    return 0;
}