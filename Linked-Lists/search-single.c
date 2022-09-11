#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void search_node(struct node *head, int element);

int main(void) {
    struct node *head = create_list();
    print_list(head);

    printf("Input the element to be searched: ");
    int element;
    scanf("%d", &element);

    search_node(head, element);
    return 0;
}

void search_node(struct node *head, int element) {
    struct node *temp = head;
    int i = 1;
    while (temp->data != element) {
        temp = temp->next;
        if (temp == NULL) {
            printf("No element found!\n");
            return;
        }
        i++;
    }
    printf("Element found at node %d\n", i);
}