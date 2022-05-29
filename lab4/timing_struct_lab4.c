#include <stdio.h>
#include <stdlib.h>
#include "struct_transf.h"
#include "sort_struct.h"
#include <time.h>
#include "errors_lab4.h"
#include "timing_struct_lab4.h"

void time_of_sort(P *all) {
    int end_len;
    int start_len;
    char *s;
    printf("*----------------------------------------------------*\n");
    printf("|              Choose sorting algorithm:             |\n");
    printf("*----------------------------------------------------*\n");
    printf("|   1 - Comb Sort                                    |\n");
    printf("|   2 - Selection Sort                               |\n");
    printf("|   3 - Insertion Binary Sort                        |\n");
    printf("*----------------------------------------------------*\n");
    printf("                    Your choice\n");
    int choice;
    s = get_str();
    choice = s_choose(s);
    if (choice == -1 || (choice != 1 && choice != 2 && choice != 3)) {
        return;
    }
    printf("*----------------------------------------------------*\n");
    printf("|               Choose start's length:               |\n");
    printf("*----------------------------------------------------*\n");
    s = get_str();
    start_len = s_choose(s);
    if (start_len == -1) {
        return;
    }
    printf("*----------------------------------------------------*\n");
    printf("|                Choose end's length:                |\n");
    printf("*----------------------------------------------------*\n");
    s = get_str();
    end_len = s_choose(s);
    if (end_len == -1) {
        return;
    }
    printf("*----------------------------------------------------*\n");
    printf("|                     Print step                     |\n");
    printf("*----------------------------------------------------*\n");
    int step;
    s = get_str();
    step = s_choose(s);
    if (step == -1) {
        return;
    }
    printf("*----------------------------------------------------*\n");
    printf("|               Print num of iterations              |\n");
    printf("*----------------------------------------------------*\n");
    int count_for_cycle;
    s = get_str();
    count_for_cycle = s_choose(s);
    if (count_for_cycle == -1) {
        return;
    }
    switch (choice) {
        case 1:
            get_array_of_time(all, start_len, end_len, step, count_for_cycle, comb_sort);
            break;
        case 2:
            get_array_of_time(all, start_len, end_len, step, count_for_cycle, selection_sort);
            break;
        case 3:
            get_array_of_time(all, start_len, end_len, step, count_for_cycle, insertion_binary_sort);
            break;
        default:
            break;
    }
}

void get_array_of_time(P *all, int start_len, int end_len, int step, int count_for_cycle,
                       void (*func)(void *, int, int, int (*)(void *, void *))) {
    double *a = calloc(((end_len - start_len)/ step) * count_for_cycle + 1000, sizeof(double));
    int count = 0;
    clock_t start, end;
    double time;
    for (int len = start_len; len <= end_len; len += step) {
        for (int i = 0; i < count_for_cycle; i++) {
            all = (P *) calloc(len, sizeof(P));
            write_str_array_random(all, len);
            start = clock();
            func(all, len, sizeof(P), num_compare);
            end = clock();
            time = ((double) (end - start)) / CLOCKS_PER_SEC;
            a[count] = time;
            count += 1;
            free_mem_struct(all, len);
        }
    }
    printf("Wolfram Mathematica ListPlot : \n");
    printf("ListPlot[{");
    for (int i = 0; i < count; i += count_for_cycle) {
        double average = 0;
        for (int j = 0; j < count_for_cycle; j++) {
            average += a[j + i];
        }
        average /= count_for_cycle;
        if (i == count - count_for_cycle) {
            printf("{%d,%lf}", start_len, average);
        } else {
            printf("{%d,%lf}, ", start_len, average);
        }
        start_len += step;
    }
    printf("}]\n");
    free(a);
}