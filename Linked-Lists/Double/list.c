#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct node *create_list() {

    int amount, value;
    printf("Input the number of nodes: ");
    scanf("%d", &amount);

    printf("Input data for node 1: ");
    scanf("%d", &value);

    struct node *head = malloc(sizeof(struct node));
    head->prev = NULL;
    head->data = value;
    head->next = NULL;

    struct node *holder = head;

    for (int i = 1; i < amount; i++) {
        printf("Input data for node %d: ", i + 1);
        scanf("%d", &value);

        struct node *current = malloc(sizeof(struct node));
        current->prev = holder;
        current->data = value;
        current->next = NULL;

        holder->next = current;
        holder = holder->next;
    }
    return head;
}

void print_list(struct node *head) {
    printf("Data entered in the list are: \n");
    struct node *print_data = head;

    int i = 1;
    while (print_data != NULL) {
        printf("Data in node %d = %d\n", i, print_data->data);
        print_data = print_data->next;
        i++;
    }
}