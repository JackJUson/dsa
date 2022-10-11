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


Tree insertAVL(Tree t, Item it);

#endif