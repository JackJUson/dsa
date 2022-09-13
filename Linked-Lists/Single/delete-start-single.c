#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct node *delete_start_list(struct node *head);

int main(void) {
    struct node *head = create_list();
    print_list(head);

    head = delete_start_list(head);
    print_list(head);

    return 0;
}

struct node *delete_start_list(struct node *head) {
    
    struct node *temp = head;
    printf("Data of node 1 which is being deleted is: %d\n", temp->data);
    head = head->next;
    free(temp);

    return head;
}