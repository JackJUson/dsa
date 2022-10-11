
#ifndef BSTREE_H
#define BSTREE_H

typedef struct Node *Tree;

typedef struct Node {
    int data;
    Tree left;
    Tree right;
} Node;

/* Define tag for tree nodes */
#define data(node) ((node)->data)
#define left(node) ((node)->left)
#define right(node) ((node)->right)

typedef int Item;

Tree TreeCreate(Item it);
void TreeFree(Tree t);
Tree TreeInsert(Tree t, Item it);
bool TreeSearch(Tree t, Item it);
Tree joinTrees(Tree t1, Tree t2);
Tree TreeDelete(Tree t, Item it);

#endif