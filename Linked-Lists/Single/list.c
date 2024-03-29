#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct node *create_list() {

    int amount, value;
    printf("Input the number of nodes: ");
    scanf("%d", &amount);

    printf("Input data for node 1: ");
    scanf("%d", &value);

    // This is a pointer that POINTS to a malloced memory space
    // Essentially acts as a placeholder. Not actually the item.
    struct node *head = malloc(sizeof(struct node));
    head->data = value;
    head->next = NULL;
    
    struct node *holder = malloc(sizeof(struct node));
    holder = head;

    int i = 1;
    while (i < amount) {
        printf("Input data for node %d: ", i + 1);
        scanf("%d", &value);

        struct node *current = malloc(sizeof(struct node));
        current->data = value;
        current->next = NULL;

        // the *next pointer of last current node struct of the linked list 
        // (that is pointed by holder) POINTS to the recently created current node
        holder->next = current;
        
        // holder pointer now POINTS to the new current malloced node
        holder = holder->next;
        i++;
    }
    return head;
}

void print_list(struct node *head) {
    printf("Data entered in the list are:\n");
    struct node *print_data = NULL;
    print_data = head;

    // traverses through the linked list and prints each data
    while (print_data != NULL) {
        printf("Data = %d\n", print_data->data);
        print_data = print_data->next;
    }
}

int count_list(struct node *head) {
    struct node *count_data = head;
    int count = 0;
    while (count_data != NULL) {
        count++;
        count_data = count_data->next;
    }
    return count;
}


// Need to create a function to free linked list
// TBC