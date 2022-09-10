#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void print_list(struct node *head);
void print_reverse(struct node *head);

int main(void) {

    struct node *head = malloc(sizeof(struct node));
    head->data = 3;
    head->next = NULL;

    struct node *current = malloc(sizeof(struct node));
    current->data = 5;
    current->next = NULL;

    // head struct pointer *next now POINTS to current 
    // (which itself is a pointer that POINTS to newly created struct node with 5 int data)
    head->next = current;

    current = malloc(sizeof(struct node));
    current->data = 7;
    current->next = NULL;

    head->next->next = current;
    
    print_list(head);
    print_reverse(head);

    return 0;
}

// Prints data of linked list in order
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

// Prints data of linked list in reverse order
void print_reverse(struct node *head) {
    printf("The list in reverse are:\n");

    // size of list
    int length = 3;
    while (length != 0) {
        int i = 1;
        struct node *print_data = NULL;
        print_data = head;

        // traverse through to the correct node relative to the size of the list
        while (i < length) {
            print_data = print_data->next;
            i++;
        }
        // prints data only once and loops back to parent loop
        printf("Data = %d\n", print_data->data);
        length--;
    }
    
}