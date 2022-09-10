#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *reverse_list(struct node *head);
void print_list(struct node *head);

int main(void) {

    int amount;
    printf("Input the number of nodes: ");
    scanf("%d", &amount);

    struct node *head = malloc(sizeof(struct node));
    head->data = 0;
    head->next = NULL;

    struct node *holder = malloc(sizeof(struct node));
    holder = head;

    int i = 1;
    while (i < amount) {

        struct node *current = malloc(sizeof(struct node));
        current->data = i;
        current->next = NULL;
        
        holder->next = current;
        holder = holder->next;
        i++;
    }

    print_list(head);
    head = reverse_list(head);
    print_list(head);

    return 0;
}

struct node *reverse_list(struct node *head) {
    struct node *temp1 = NULL;
    struct node *temp2 = NULL;
    while (head != NULL) {
        // temp1 holds next struct node
        temp1 = head->next;

        // current head *next pointer POINTS to NULL of temp2 --> Very first node will have NULL as pointed
        head->next = temp2;

        // temp2 pointer now POINTS to the current (first) node --> This holds and saves the first (previous) node, so they we can change pointer without losing the node
        temp2 = head;

        // head pointer now POINTS to the next node --> This is valid since the first (previous) node is saved in temp2
        head = temp1;
    }

    // head now points to the very last node, which represents the beginning of reversed list
    head = temp2;
    return head;
}

// Prints data of linked list in order
void print_list(struct node *head) {
    printf("Data entered in the list are:\n");

    struct node *print_data = NULL;
    print_data = head;
    while (print_data != NULL) {
        printf("Data = %d\n", print_data->data);
        print_data = print_data->next;
    }
}