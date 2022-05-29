#ifndef UNTITLED2_LIST_LAB6_H
#define UNTITLED2_LIST_LAB6_H

typedef struct Node {
    char value;
    struct Node *next;
} Node;

Node *delete_spaces(Node *);

Node *createList();

void printList(Node *);

void freeList(Node *);

void reverse_elements(Node **, Node **, Node **);

Node *reverse_letters(Node *);

void add_space(Node **, Node **);

#endif //UNTITLED2_LIST_LAB6_H
