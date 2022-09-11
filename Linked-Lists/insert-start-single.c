#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct node *insert_start_list(struct node *head, int num);

int main(void) {
    struct node *head = create_list();
    print_list(head);

    printf("Input data to insert at the beginning of the list: ");
    int num = 0;
    scanf("%d", &num);

    head = insert_start_list(head, num);
    print_list(head);

    return 0;
}

struct node *insert_start_list(struct node *head, int num) {
    struct node *new_node = malloc(sizeof(struct node));
    
    new_node->data = num;
    new_node->next = head;

    return new_node;
}

