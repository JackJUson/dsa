#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void print_reverse(struct node *head);

int main(void) {

    struct node *head = create_list();
    print_list(head);

    print_reverse(head);

    return 0;
}

void print_reverse(struct node *head) {
    printf("Data in reverse order are: \n");

    struct node *print_data = head;
    while (print_data->next != NULL) {
        print_data = print_data->next;
    }

    int i = 1;
    while (print_data != NULL) {
        printf("Data in node %d: %d\n", i, print_data->data);
        print_data = print_data->prev;
    }
}