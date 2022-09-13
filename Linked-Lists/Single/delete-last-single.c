#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct node *delete_last_node(struct node *head);

int main(void) {
    struct node *head = create_list();
    print_list(head);

    head = delete_last_node(head);
    print_list(head);

    return 0;
}

struct node *delete_last_node(struct node *head) {
    
    struct node *temp = head;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;

    printf("The new list after deletion the last node are: \n");
    return head;
}