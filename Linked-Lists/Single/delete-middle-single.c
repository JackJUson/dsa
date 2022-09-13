#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct node *delete_middle_list(struct node *head, int position);

int main(void) {
    struct node *head = create_list();
    print_list(head);

    printf("Input the position of node to delete: ");
    int position;
    scanf("%d", &position);

    head = delete_middle_list(head, position);
    print_list(head);

    return 0;
}

struct node *delete_middle_list(struct node *head, int position) {
    
    struct node *temp1 = head;
    struct node *temp2 = NULL;
    
    int i = 2;
    while (i < position) {
        temp1 = temp1->next;
        i++;
    }
    temp2 = temp1->next->next;
    free(temp1->next);
    temp1->next = temp2;

    printf("Deletion completed successfully.");
    return head;
}