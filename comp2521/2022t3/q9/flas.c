
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

List flas(List l) {
    // TODO
    // We need to iterate through the list and count the start of the ascend

    // Arrays of List, containing all possible ascending lists of given list
    int length = 0;
    for (List temp = l; temp != NULL; temp = temp->next) {
        length++;
    }
    // Create the list array and null all the list
    List *array = malloc(length * sizeof(List));
    for (int i = 0; i < length; i++) {
        array[i] = ListNew();
    }

    int index = 0;
    // Iterate through and add all possible ascending list in array
    for (List temp = l; temp->next != NULL; temp = temp->next) {
        if (temp->value < temp->next->value) {
            array[index] = ListInsert(array[index], temp->value);
            for (List temp2 = temp; temp2->next != NULL && temp2->value < temp2->next->value; temp2 = temp2->next) {
                array[index] = ListInsert(array[index], temp2->next->value);
            }
        }
        index++;
    }

    int max = 0;
    int *lengthArray = calloc(length, sizeof(int));
    for (int i = 0; i < length; i++) {
        int listLength = 0;
        for (List temp3 = array[i]; temp3 != NULL; temp3 = temp3->next) {
            listLength++;
        }
        lengthArray[i] = listLength;
    }

    int saveIndex = 0;
    for (int j = 0; j < length; j++) {
        if (max < lengthArray[j]) {
            max = lengthArray[j];
            saveIndex = j;
        }
    }
    List final = l;
    for (int i = 0; i < saveIndex; i++) {
        final = final->next;
    }

    // free array
    for (int i = 0; i < length; i++) {
        ListFree(array[i]);
    }
    free(array);

    free(lengthArray);
    // Returns the pointer to the node (node) at the start of longest ascending sublist
    return final;
}

// List flas(List l) {
//     List flas = NULL;
//     int flasLen = 0;

//     List curr = l;
//     while (curr != NULL) {
//         List start = curr;
//         int len = 1;

//         while (curr->next != NULL && curr->next->value > curr->value) {
//             len++;
//             curr = curr->next;
//         }

//         if (len > flasLen && len >= 2) {
//             flas = start;
//             flasLen = len;
//         }
//         curr = curr->next;
//     }

//     return flas;
// }
