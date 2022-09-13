#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct node *insert_middle_list(struct node *head, int num, int position);

int main(void) {
    struct node *head = create_list();
    print_list(head);

    printf("Input data to insert in the middle of the list: ");
    int num = 0;
    scanf("%d", &num);

    printf("Input the position to insert new node: ");
    int position = 0;
    scanf("%d", &position);

    head = insert_middle_list(head, num, position);
    print_list(head);

    return 0;
}

struct node *insert_middle_list(struct node *head, int num, int position) {

    struct node *temp = head;
    int i = 1;
    position = position - 1;
    while (i < position) {
        temp = temp->next;
        i++;
    }

    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = temp->next;
    temp->next = new_node;
    
    return head;
}

