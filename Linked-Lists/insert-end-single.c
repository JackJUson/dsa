#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct node *insert_end_list(struct node *head, int num);

int main(void) {
    struct node *head = create_list();
    print_list(head);

    printf("Input data to insert at the end of the list: ");
    int num = 0;
    scanf("%d", &num);

    head = insert_end_list(head, num);
    print_list(head);

    return 0;
}

struct node *insert_end_list(struct node *head, int num) {

    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    struct node *new_node = malloc(sizeof(struct node));
    
    new_node->data = num;
    new_node->next = NULL;
    temp->next = new_node;
    return head;
}

