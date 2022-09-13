#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct node *insert_end_double(struct node *head, int value);

int main(void) {
    struct node *head = create_list();
    print_list(head);

    int value;
    printf("Input data for the first node: ");
    scanf("%d", &value);

    head = insert_end_double(head, value);
    print_list(head);
    return 0;
}

struct node *insert_end_double(struct node *head, int value) {
    struct node *temp1 = malloc(sizeof(struct node));
    struct node *temp2 = head;
    while (temp2->next != NULL) {
        temp2 = temp2->next;
    }

    temp1->next = NULL;
    temp1->data = value;
    temp1->prev = temp2;

    temp2->next = temp1;

    return head;
}