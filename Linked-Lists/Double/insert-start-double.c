#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct node *insert_start_double(struct node *head, int value);

int main(void) {
    struct node *head = create_list();
    print_list(head);

    int value;
    printf("Input data for the first node: ");
    scanf("%d", &value);

    head = insert_start_double(head, value);
    print_list(head);
    return 0;
}

struct node *insert_start_double(struct node *head, int value) {
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = value;
    head->prev = temp;
    temp->next = head;

    head = temp;

    return head;
}