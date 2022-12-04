
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "BSTree.h"

void CurrentLevel(BSTree root, int level, int *array, int index);

int minDiff(BSTree t, int l) {
    // Make int array, store the values, calculate and return them and return max
    int *array = calloc(10, sizeof(int));
    CurrentLevel(t, l + 1, array, 0);
    int min = array[0];
    // find the min within the array
    for (int i = 0; i < 10; i++) {
      if (array[i] != 0) {
        if (min > array[i]) {
          min = array[i];
        }
      }
    }

    free(array);
    return min;
}

void CurrentLevel(BSTree root, int level, int *array, int index) {
  int dif = 0;
  if (root == NULL) {
    return;
  } else if (level > 1) {
    if (root->left != NULL && root->right != NULL) {
        dif = abs(root->left->key - root->right->key);
        array[index] = dif;
        index++;
    }
    CurrentLevel(root->left, level - 1, array, index);
    CurrentLevel(root->right, level - 1, array, index);
  }
}

// Level order BST traversal without Queue
void BSTPrintLevelOrder(Tree t) {
    int h = height(t);
    for (int i = 1; i <= h; i++) {
        CurrentLevel(t, i);
    }
}

void CurrentLevel(Tree t, int level) {
    if (t == NULL) {
        return;
    }
    if (level == 1) {
        printf("%d\n", t->value);
    } else if (level > 1) {
        CurrentLevel(t->left, level - 1);
        CurrentLevel(t->right, level - 1);
    }
}

// static void doMinDiff(BSTree t, int l, bool *firstVal, int *prev, int *min);

// int minDiff(BSTree t, int l) {
//     // TODO
//     bool firstVal = true;
//     int prev = 0;
//     int min = 0;
//     doMinDiff(t, l, &firstVal, &prev, &min);
//     return min;
// }

// static void doMinDiff(BSTree t, int l, bool *firstVal, int *prev, int *min) {
//     if (t == NULL) {
//         return;
//     }
//     if (l == 0) {
//         if (*firstVal) {
//             *prev = t->key;
//             *firstVal = false;
//         } else {
//             if (*min == 0 || t->key - *prev < *min) {
//                 *min = t->key - *prev;
//             }
//             *prev = t->key;
//         }
//         return;
//     }
//     doMinDiff(t->left, l - 1, firstVal, prev, min);
//     doMinDiff(t->right, l - 1, firstVal, prev, min);
// }

