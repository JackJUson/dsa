#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct node *reverse_list(struct node *head);

int main(void) {

    struct node *head = create_list();
    print_list(head);
    head = reverse_list(head);
    print_list(head);

    return 0;
}

struct node *reverse_list(struct node *head) {
    struct node *temp1 = NULL;
    struct node *temp2 = NULL;
    while (head != NULL) {
        // temp1 holds next struct node
        temp1 = head->next;

        // current head *next pointer POINTS to NULL of temp2 --> Very first node will have NULL as pointed
        head->next = temp2;

        // temp2 pointer now POINTS to the current (first) node --> This holds and saves the first (previous) node, so they we can change pointer without losing the node
        temp2 = head;

        // head pointer now POINTS to the next node --> This is valid since the first (previous) node is saved in temp2
        head = temp1;
    }

    // head now points to the very last node, which represents the beginning of reversed list
    head = temp2;
    return head;
}
