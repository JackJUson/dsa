#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void count_list(struct node *head);

int main(void) {

    int amount, value;
    printf("Input the number of nodes: ");
    scanf("%d", &amount);

    printf("Input data for node 1: ");
    scanf("%d", &value);

    struct node *head = malloc(sizeof(struct node));
    head->data = value;
    head->next = NULL;
    struct node *holder = malloc(sizeof(struct node));
    holder = head;

    int i = 1;
    while (i < amount) {
        printf("Input data for node %d: ", i);
        scanf("%d", &value);

        struct node *current = malloc(sizeof(struct node));
        current->data = value;
        current->next = NULL;

        holder->next = current;
        holder = holder->next;
        i++;
    }
    count_list(head);
    return 0;
}

void count_list(struct node *head) {
    struct node *count_data = head;
    int count = 0;
    while (count_data != NULL) {
        count++;
        count_data = count_data->next;
    }
    printf("Total number of nodes = %d\n", count);
}