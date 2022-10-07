
#ifndef BSTREE_H
#define BSTREE_H

typedef struct Node *Tree;

typedef struct Node {
    int data;
    Tree left;
    Tree right;
} Node;

typedef int Item;

Tree TreeCreate(Item it);

void TreeFree(Tree t);

Tree TreeInsert(Tree t, Item it);


Item TreeNumNodes(Tree t);

bool TreeSearch(Tree t, Item it);

Tree joinTrees(Tree t1, Tree t2);

Tree TreeDelete(Tree t, Item it);

Tree rotateRight(Tree n1);

Tree rotateLeft(Tree n1);


Tree insertAtRoot(Tree t, Item it);

Tree partition(Tree t, int index);


Tree BSTreeGetSmallest(Tree t);

int TreeHeight(Tree t);

int BSTreeNodeHeight(Tree t, int key);

#endif