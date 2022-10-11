// Binary Search Tree ADT Tester ... 

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "BSTree.h"
#include "BSTPrint.h"
#include "BSTBalance.h"

int main(int argc, char *argv[]) {
    
    Tree t = TreeCreate(4);
    t = TreeInsert(t, 5);
    t = TreeInsert(t, 7);
    t = TreeInsert(t, 3);
    t = TreeInsert(t, 6);
    t = TreeInsert(t, 1);
    t = TreeInsert(t, 2);


    showTreeIn(t, 0);

    TreeFree(t);
    /*
    // List style print
    showTree(t);
    printf("\nline break\n");
    // Inorder style print 
    showTreeIn(t, 0);
    printf("\nline break\n");
    showTreePre(t, 0);
    printf("\nline break\n");
    showTreePost(t, 0);
    printf("\nline break\n");
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

    Tree t3 = t1;
    Tree t4 = t1;

    t3 = TreeDelete(t3, 30);

    printf("Delete 30 from Tree t1:\n");
    showTreeIn(t3, 0);

    t4 = TreeDelete(t4, 24);
    printf("Delete 24 from Tree t1:\n");
    showTreeIn(t4, 0);

    Tree n1 = TreeCreate(5);
    n1 = TreeInsert(n1, 6);
    n1 = TreeInsert(n1, 3);
    n1 = TreeInsert(n1, 2);
    n1 = TreeInsert(n1, 4);

    printf("\nTree n1:\n");
    showTreeIn(n1, 0);
    n1 = rotateRight(n1);
    printf("\nTree n1 after rotate right:\n");
    showTreeIn(n1, 0);

    n1 = rotateLeft(n1);
    printf("\nTree n1 after rotate left:\n");
    showTreeIn(n1, 0);
    
//////

    Tree t = TreeCreate(10);
    t = TreeInsert(t, 5);
    t = TreeInsert(t, 14);
    t = TreeInsert(t, 30);
    t = TreeInsert(t, 29);
    t = TreeInsert(t, 32);
    printf("Original tree: \n");
    showTreeIn(t, 0);

    t = insertAtRoot(t, 24);
    printf("Tree with 24 inserted at root: \n");
    showTreeIn(t, 0);
    TreeFree(t);
    
    printf("Original tree: \n");
    t = TreeCreate(10);
    t = TreeInsert(t, 5);
    t = TreeInsert(t, 14);
    t = TreeInsert(t, 30);
    t = TreeInsert(t, 29);
    t = TreeInsert(t, 32);
    showTreeIn(t, 0);

    t = partition(t, 3);
    printf("Tree partition at node 29:\n");
    showTreeIn(t, 0);

    TreeFree(t);
    */

    return 0;
}