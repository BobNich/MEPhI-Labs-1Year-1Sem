#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "struct_transf.h"
#include "file_struct.h"
#include "sort_struct.h"
#include "timing_struct_lab4.h"
#include "errors_lab4.h"

int main() {
    srand(time(NULL));
    FILE *file_struct;
    int len = 0;
    char *s;
    int field;
    int index;
    char *name_of_file;
    int flag_sort_n = 0;
    int flag_sort_str = 0;
    int flag_sort_num = 0;
    int choice;
    P *all;
    P *st_buffer;
    printf("*----------------------------------------------------*\n");
    printf("|           Your struct contains 3 members.          |\n");
    printf("|            1) N - string with 8 symbols.           |\n");
    printf("|           2) STR - string with n-symbols.          |\n");
    printf("|              3) NUM - natural number.              |\n");
    printf("*----------------------------------------------------*\n");
    do {
        printf("*----------------------------------------------------*\n");
        printf("|                        Menu                        |\n");
        printf("*----------------------------------------------------*\n");
        printf("|   1 - Input array                                  |\n");
        printf("|   2 - Put element in array by index                |\n");
        printf("|   3 - Delete elements from array by index and len  |\n");
        printf("|   4 - Input array from file                        |\n");
        printf("|   5 - Write array to file                          |\n");
        printf("|   6 - Random array generation                      |\n");
        printf("|   7 - Selection sort                               |\n");
        printf("|   8 - Comb sort                                    |\n");
        printf("|   9 - Insertion Binary sort                        |\n");
        printf("|  10 - Print current array                          |\n");
        printf("|  11 - Put in sorted                                |\n");
        printf("|  12 - Time                                         |\n");
        printf("*----------------------------------------------------*\n");
        printf("|   0 - Quit menu                                    |\n");
        printf("*----------------------------------------------------*\n");
        printf("                    Your choice\n");
        s = get_str();
        choice = s_choose(s);
        switch (choice) {
            case 1:
                free_mem_struct(all, len);
                flag_sort_n = flag_sort_str = flag_sort_num = 0;
                printf("Print length of array:\n");
                s = get_str();
                len = s_choose(s);
                if (len == 0) {
                    break;
                }
                all = (P *) calloc(len, sizeof(P));
                structure_input(all, len);
                break;
            case 2:
                flag_sort_n = flag_sort_str = flag_sort_num = 0;
                if (len_error(len)){
                    break;
                }
                printf("Print INDEX:\n");
                s = get_str();
                index = s_choose(s);
                if (index == -1){
                    break;
                }
                if (index >= len + 1 || index < 0) {
                    printf("*----------------------------------------------------*\n");
                    printf("              !  ERROR : Invalid index  !\n");
                    printf("*----------------------------------------------------*\n");
                    break;
                }
                st_buffer = (P *) calloc(1, sizeof(P));
                structure_input(st_buffer, 1);
                all = put_by_index(all, st_buffer, &len, index);
                free(st_buffer[0].n);
                break;
            case 3:
                flag_sort_n = flag_sort_str = flag_sort_num = 0;
                if (len_error(len)){
                    break;
                }
                all = delete_by_indexes(all, &len);
                break;
            case 4:
                flag_sort_n = flag_sort_str = flag_sort_num = 0;
                printf("Print name of file:\n");
                name_of_file = get_str();
                if (!(file_struct = fopen(name_of_file, "r"))) {
                    printf("*----------------------------------------------------*\n");
                    printf("         !  ERROR : Invalid name of file  !\n");
                    printf("*----------------------------------------------------*\n");
                    fclose(file_struct);
                    free(name_of_file);
                    break;
                }
                free_mem_struct(all, len);
                int is_error = is_structure_from_file_ok(file_struct);
                if (is_error == 0) {
                    free(name_of_file);
                    break;
                }
                file_struct = fopen(name_of_file, "r");
                char *f = get_str_file(file_struct);
                len = (int) atoi(f);
                free(f);
                all = (P *) calloc(len, sizeof(P));
                structure_input_file(file_struct, all, len);
                fclose(file_struct);
                free(name_of_file);
                break;
            case 5:
                printf("Print name of file:\n");
                name_of_file = get_str();
                if (!(file_struct = fopen(name_of_file, "w"))){
                    printf("*----------------------------------------------------*\n");
                    printf("         !  ERROR : Invalid name of file  !\n");
                    printf("*----------------------------------------------------*\n");
                    fclose(file_struct);
                    free(name_of_file);
                    break;
                }
                write_str_array_file(all, len, file_struct);
                free(name_of_file);
                break;
            case 6:
                flag_sort_n = flag_sort_str = flag_sort_num = 0;
                free_mem_struct(all, len);
                printf("Print length of random array:\n");
                s = get_str();
                len = s_choose(s);
                if (len <= 0) {
                    len = 0;
                    break;
                }
                all = (P *) calloc(len, sizeof(P));
                write_str_array_random(all, len);
                break;
            case 7:
                if (len_error(len)){
                    break;
                }
                printf("Select field (1 - n, 2 - str, 3 - num):\n");
                s = get_str();
                field = s_choose(s);
                if (field == -1){
                    break;
                }
                if (field == 1) {
                    selection_sort(all, len, sizeof(P), n_compare);
                    flag_sort_n = 1;
                    flag_sort_str = flag_sort_num = 0;
                } else if (field == 2) {
                    selection_sort(all, len, sizeof(P), str_compare);
                    flag_sort_str = 1;
                    flag_sort_n = flag_sort_num = 0;
                } else if (field == 3) {
                    selection_sort(all, len, sizeof(P), num_compare);
                    flag_sort_num = 1;
                    flag_sort_n = flag_sort_str = 0;
                }
                break;
            case 8:
                if (len_error(len)){
                    break;
                }
                printf("Select field (1 - n, 2 - str, 3 - num):\n");
                s = get_str();
                field = s_choose(s);
                if (field == -1){
                    break;
                }
                if (field == 1) {
                    flag_sort_n = 1;
                    flag_sort_str = 0;
                    flag_sort_num = 0;
                    comb_sort(all, len, sizeof(P), n_compare);
                } else if (field == 2) {
                    comb_sort(all, len, sizeof(P), str_compare);
                    flag_sort_str = 1;
                    flag_sort_n = 0;
                    flag_sort_num = 0;
                } else if (field == 3) {
                    flag_sort_num = 1;
                    flag_sort_n = 0;
                    flag_sort_str = 0;
                    comb_sort(all, len, sizeof(P), num_compare);
                }
                break;
            case 9:
                if (len_error(len)){
                    break;
                }
                printf("Select field (1 - n, 2 - str, 3 - num):\n");
                s = get_str();
                field = s_choose(s);
                if (field == -1){
                    break;
                }
                if (field == 1) {
                    flag_sort_n = 1;
                    flag_sort_str = 0;
                    flag_sort_num = 0;
                    insertion_binary_sort(all, len, sizeof(P), n_compare);
                } else if (field == 2) {
                    insertion_binary_sort(all, len, sizeof(P), str_compare);
                    flag_sort_str = 1;
                    flag_sort_n = 0;
                    flag_sort_num = 0;
                } else if (field == 3) {
                    flag_sort_num = 1;
                    flag_sort_n = 0;
                    flag_sort_str = 0;
                    insertion_binary_sort(all, len, sizeof(P), num_compare);
                }
                break;
            case 10:
                if (len_error(len)){
                    break;
                }
                print_str_array(all, len);
                break;
            case 11:
                if (len_error(len)){
                    break;
                }
                printf("Select field (1 - n, 2 - str, 3 - num):\n");
                s = get_str();
                field = s_choose(s);
                if (field == -1){
                    break;
                }
                if (field == 1 && flag_sort_n == 0) {
                    printf("*----------------------------------------------------*\n");
                    printf("      !  ERROR : You can't sort by this field  !\n");
                    printf("*----------------------------------------------------*\n");
                    break;
                } else if (field == 2 && flag_sort_str == 0) {
                    printf("*----------------------------------------------------*\n");
                    printf("      !  ERROR : You can't sort by this field  !\n");
                    printf("*----------------------------------------------------*\n");
                    break;
                } else if (field == 3 && flag_sort_num == 0) {
                    printf("*----------------------------------------------------*\n");
                    printf("      !  ERROR : You can't sort by this field  !\n");
                    printf("*----------------------------------------------------*\n");
                    break;
                }
                st_buffer = (P *) calloc(1, sizeof(P));
                structure_input(st_buffer, 1);
                if (field == 1) {
                    all = put_in_sorted(all, st_buffer, &len, sizeof(P), field);
                } else if (field == 2) {
                    all = put_in_sorted(all, st_buffer, &len, sizeof(P), field);
                } else if (field == 3) {
                    all = put_in_sorted(all, st_buffer, &len, sizeof(P), field);
                }
                free(st_buffer[0].n);
                break;
            case 12:
                time_of_sort(all);
                len = 0;
            default:
                break;
        }
    } while (choice);
    free_mem_struct(all, len);
    printf("*----------------------------------------------------*\n");
    printf("|        Bye bye, my friend! See you soon ;)         |\n");
    printf("*----------------------------------------------------*\n");
    return 0;
}