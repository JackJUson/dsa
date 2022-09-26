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
    //showTree(t);
    showTreeIn(t, 0);
    //showTreePre(t, 0);
    //showTreePost(t, 0);
    return 0;
}