#include <string.h>
#include <stdlib.h>
#include "struct_transf.h"
#include "sort_struct.h"

//swap by field
void swap(void *first, void *second, int size) {
    void *tmp = malloc(size);
    memcpy(tmp, first, size);
    memcpy(first, second, size);
    memcpy(second, tmp, size);
    free(tmp);
}

int str_compare(void *first, void *second) {
    P *pt1 = (P *) first;
    P *pt2 = (P *) second;
    int result = 0;
    if (strcmp((pt1->str), (pt2->str)) < 0) {
        result = -1;
    } else if (strcmp((pt1->str), (pt2->str)) > 0) {
        result = 1;
    }
    return result;
}

int n_compare(void *first, void *second) {
    P *pt1 = (P *) first;
    P *pt2 = (P *) second;
    int result = 0;
    if (strcmp((pt1->n), (pt2->n)) < 0) {
        result = -1;
    } else if (strcmp((pt1->n), (pt2->n)) > 0) {
        result = 1;
    }
    return result;
}

int num_compare(void *first, void *second) {
    P *pt1 = (P *) first;
    P *pt2 = (P *) second;
    int result = 0;
    if ((pt1->num) < (pt2->num)) {
        result = -1;
    } else if ((pt1->num) > (pt2->num)) {
        result = 1;
    }
    return result;
}

//selection sort n
void selection_sort(void *all, int len, int size, int (*compare)(void *, void *)) {
    for (int i = 0; i < len - 1; i++) {
        int min = i;
        for (int j = i + 1; j < len; j++) {
            if (compare((all + j * size), (all + min * size)) == -1) {
                min = j;
            }
        }
        if (min != i) {
            swap((all + i * size), (all + min * size), size);
        }
    }
}

//comb sort num
void comb_sort(void *all, int len, int size, int (*compare)(void *, void *)) {
    double shrink = 1.2473309;
    int stp = len - 1;
    while (stp >= 1) {
        for (int i = 0; i + stp < len; i++) {
            if (compare((all + (i + stp) * size), (all + i * size)) == -1) {
                swap((all + i * size), (all + (i + stp) * size), size);
            }
        }
        stp = (int) (stp / shrink);
    }
}

//insertion binary sort num
void insertion_binary_sort(void *all, int len, int size, int (*compare)(void *, void *)) {
    int j;
    for (int i = 1; i < len; i++) {
        j = i - 1;
        void *tmp = malloc(size);
        memcpy(tmp, all + i * size, size);
        int k = bin_search(all, i, size, all + size * i, *compare);
        while (j >= k) {
            memcpy(all + (j + 1) * size, all + j * size, size);
            j--;
        }
        memcpy(all + (j + 1) * size, tmp, size);
        free(tmp);
    }
}


int bin_search(void *all, int len_for_bin, int size, void *element, int (*compare)(void *, void *)) {
    int right_index = len_for_bin;
    int left_index = 0;
    while (left_index < right_index) {
        int m = (left_index + right_index) / 2;
        if (compare((all + m * size), element) == 1) {
            right_index = m;
        } else {
            left_index = m + 1;
        }
    }
    return right_index;
}