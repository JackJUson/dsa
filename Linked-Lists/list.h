#ifndef LIST_H
#define LIST_H


#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *create_list();

void print_list(struct node *head);

int count_list(struct node *head);

#endif