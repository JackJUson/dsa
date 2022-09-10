#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

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
    
    print_reverse(head);

    return 0;
}

void print_reverse(struct node *head) {

}