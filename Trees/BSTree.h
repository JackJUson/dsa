typedef struct Node *Tree;

typedef int Item;

Tree TreeCreate(Item it);

void TreeFree(Tree t);

Tree TreeInsert(Tree t, Item it);

void showTree(Tree t);

Item TreeNumNodes(Tree t);

void showTreeIn(Tree t, int zero);
void showTreePre(Tree t, int zero);
void showTreePost(Tree t, int zero);