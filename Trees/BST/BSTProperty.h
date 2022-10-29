
#ifndef BSTPROPERTY_H
#define BSTPROPERTY_H

Item TreeNumNodes(Tree t);
int TreeHeight(Tree t);
Tree BSTreeGetSmallest(Tree t);
int BSTreeNodeHeight(Tree t, int key);
int BSTreeNumLeaves(Tree t);
Tree BSTreeDeleteLeaves(Tree t);

int BSTreeCountOdds(Tree t);
int BSTreeCountInternal(Tree t);
int BSTreeCountGreater(BSTree t, int val);

#endif