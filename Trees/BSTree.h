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

Tree rotateRight(Tree n1);

Tree rotateLeft(Tree n1);

Tree partition(Tree t, int i);

Tree BSTreeGetSmallest(Tree t);

int TreeHeight(Tree t);

void showTreeIn(Tree t, int zero);
void showTreePre(Tree t, int zero);
void showTreePost(Tree t, int zero);