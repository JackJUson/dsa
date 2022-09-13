#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct node *insert_middle_double(struct node *head, int value, int position);

int main(void) {
    struct node *head = create_list();
    print_list(head);

    int position;
    printf("Input the position to insert a new node: ");
    scanf("%d", &position);

    int value;
    printf("Input data for the position %d: ", position);
    scanf("%d", &value);

    head = insert_middle_double(head, value, position);
    print_list(head);
    return 0;
}

struct node *insert_middle_double(struct node *head, int value, int position) {
    
    struct node *temp1 = malloc(sizeof(struct node));
    struct node *temp2 = head;
    position = position - 1;
    for (int i = 1; i < position; i++) {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp1->data = value;
    temp1->prev = temp2;

    temp2->next = temp1;

    return head;
}