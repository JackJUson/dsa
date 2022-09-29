typedef struct Node *Tree;

typedef int Item;

Tree TreeCreate(Item it);

void TreeFree(Tree t);

Tree TreeInsert(Tree t, Item it);

void showTree(Tree t);

Item TreeNumNodes(Tree t);

bool TreeSearch(Tree t, Item it);

Tree joinTrees(Tree t1, Tree t2);

Tree TreeDelete(Tree t, Item it);

void showTreeIn(Tree t, int zero);
void showTreePre(Tree t, int zero);
void showTreePost(Tree t, int zero);