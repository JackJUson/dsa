typedef struct Node *Tree;

typedef int Item;

Tree TreeCreate(Item it);
void TreeFree(Tree t);
Tree TreeInsert(Tree t, Item it);
void showTree(Tree t);