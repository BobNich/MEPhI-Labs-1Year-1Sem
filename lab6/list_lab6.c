#include <stdio.h>
#include <stdlib.h>
#include "list_lab6.h"

Node *reverse_letters(Node *head) {

    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;

    Node *head_word = head;
    Node *tail_word;

    int k = 0;
    int c = 0;

    while (current != NULL) {
        if (current->value != ' ' && k == 0) {
            k = 1;
            head_word = current;
            reverse_elements(&next, &current, &prev);
        } else if (current->value != ' ' && k == 1) {
            reverse_elements(&next, &current, &prev);
        } else {
            if (c == 0) {
                head = prev;
                tail_word = current;
                head_word->next = tail_word;
                current = current->next;
                prev = NULL;
                c = 1;
            } else {
                tail_word->next = prev;
                head_word->next = current;
                tail_word = current;
                current = current->next;
                prev = NULL;
            }
            k = 0;
        }
    }
    if (c == 0) {
        head = prev;
    } else {
        tail_word->next = prev;
        head_word->next = current;
    }
    return head;
}

void reverse_elements(Node **next, Node **current, Node **prev) {
    *next = (*current)->next;
    (*current)->next = *prev;
    *prev = *current;
    *current = *next;
}

void printList(Node *head) {
    Node *current_head = head;
    printf("Your string's:\n");
    printf("\"");
    while (current_head != NULL) {
        printf("%c", current_head->value);
        current_head = current_head->next;
    }
    printf("\"");
    printf("\n");
}

void freeList(Node *head) {
    Node *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

Node *createList() {
    char letter;
    Node *element = (Node *) malloc(sizeof(Node));
    Node *head = element;
    if ((letter = (char) getchar()) == EOF) {
        free(element);
        return NULL;
    }
    element->value = letter;
    if (element->value == '\n'){
        element->next = NULL;
        return head;
    }
    while ((letter = (char) getchar()) != '\n') {
        element->next = (Node *) malloc(sizeof(Node));
        element = element->next;
        element->value = letter;
        element->next = NULL;
    }
    element->next = NULL;
    return head;
}


Node *delete_spaces(Node *head) {
    Node *current = head;
    Node *prev;
    Node *tmp;
    int k = 0;
    while (current != NULL && (current->value == ' ' || current->value == '\t')) {
        tmp = current;
        current = current->next;
        head = current;
        free(tmp);
    }
    if (!current) {
        return head;
    }
    while (current != NULL) {
        if (current->value == ' ' || current->value == '\t') {
            k = 1;
            tmp = current;
            current = current->next;
            free(tmp);
        } else if (k == 1 && (current->value != ' ' || current->value != '\t')) {
            k = 0;
            add_space(&prev, &current);
        } else {
            prev = current;
            current = current->next;
            k = 0;
        }
    }
    prev->next = NULL;
    return head;
}

void add_space(Node ** prev, Node ** current){
    Node *new = malloc(sizeof(Node));
    new->value = ' ';
    (*prev)->next = new;
    new->next = *current;
    *prev = *current;
    *current = (*current)->next;
}