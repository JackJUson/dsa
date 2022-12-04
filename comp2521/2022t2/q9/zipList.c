
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

List ListInsert(List l, int value);

// Worst case time complexity of this solution: O(n + m)
List zipList(List l1, int x, List l2, int y) {

    List l = ListNew();
    if (x == 0 && y == 0) {
        return l;
    }

    Node curr1 = l1->first;
    Node curr2 = l2->first;

    int i = 0;
    int j = 0;

    while ((curr1 != NULL && x > 0) || (curr2 != NULL && y > 0)) {
        if (i == 0) {
            while (i < x && curr1 != NULL) {
                l = ListInsert(l, curr1->value);
                curr1 = curr1->next;
                i++;
            }
            i = 0;
        } 
        
        if (j == 0) {
            while (j < y && curr2 != NULL) {
                l = ListInsert(l, curr2->value);
                curr2 = curr2->next;
                j++;
            }
            j = 0;
        }
    }

    return l;
}

List ListInsert(List l, int value) {
    Node n = newNode(value);
    if (l->first == NULL) {
        l->first = n;
        l->last = n;
        return l;
    }
    l->last->next = n;
    l->last = n;
    return l;
}