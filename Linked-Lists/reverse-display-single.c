#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void print_reverse(struct node *head, int count);

int main(void) {

    struct node *head = create_list();
    print_list(head);
    int count = count_list(head);
    print_reverse(head, count);

    return 0;
}

// Prints data of linked list in reverse order
void print_reverse(struct node *head, int count) {
    printf("The list in reverse are:\n");

    // size of list
    int list_size = count;
    while (list_size != 0) {
        int i = 1;
        struct node *print_data = NULL;
        print_data = head;

        // traverse through to the correct node relative to the size of the list
        while (i < list_size) {
            print_data = print_data->next;
            i++;
        }
        // prints data only once and loops back to parent loop
        printf("Data = %d\n", print_data->data);
        list_size--;
    }
}