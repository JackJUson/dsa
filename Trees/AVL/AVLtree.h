#ifndef AVLTREE_H
#define AVLTREE_H

typedef struct Node *Tree;

typedef struct Node {
    int data;
    Tree left;
    Tree right;
    int height;
} Node;

/* Define tag for tree nodes */
#define data(node) ((node)->data)
#define left(node) ((node)->left)
#define right(node) ((node)->right)

typedef int Item;

int height(Tree t);
int max(int a, int b);
Tree TreeCreate(Item it);
Tree insertAVL(Tree t, Item it);

Tree rightRotate(Tree y);
Tree leftRotate(Tree y);

#endif