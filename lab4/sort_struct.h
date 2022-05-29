#ifndef UNTITLED2_SORT_STRUCT_H
#define UNTITLED2_SORT_STRUCT_H

void swap(void *, void *, int);

void selection_sort(void *, int, int, int (*f)(void *, void *));

void comb_sort(void *, int, int, int (*f)(void *, void *));

void insertion_binary_sort(void *, int, int, int (*f)(void *, void *));

int str_compare(void *, void *);

int n_compare(void *, void *);

int num_compare(void *, void *);

int bin_search(void *, int, int, void *, int (*f)(void *, void *));

#endif //UNTITLED2_SORT_STRUCT_H
