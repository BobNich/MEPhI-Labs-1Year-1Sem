#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct_transf.h"
#include "errors_lab4.h"

// input structure(s) from keyboard
void structure_input(P *all, int len) {
    int error = 1;
    int error2 = 1;
    int for_num = 1;
    char *buf;
    char *buf2;
    for (int i = 0; i < len; i++) {
        while (error) {
            printf("Enter N\n");
            buf = get_str();
            if (strlen(buf) != 8) {
                printf("*----------------------------------------------------*\n");
                printf("             !  ERROR : Len of n != 8  !\n");
                printf("*----------------------------------------------------*\n");
                free(buf);
            } else {
                strcpy(all[i].n, buf);
                free(buf);
                error = 0;
            }
        }
        error = 1;
        printf("Enter STR\n");
        all[i].str = get_str();
        int count = 0;
        while (error2) {
            printf("Enter NUM\n");
            buf2 = get_str();
            for (int j = 0; j < strlen(buf2); j++) {
                if (!(buf2[j] >= '0' && buf2[j] <= '9')) {
                    count += 1;
                    if (count == 1) {
                        printf("*----------------------------------------------------*\n");
                        printf("              !  ERROR : Not integer  !\n");
                        printf("*----------------------------------------------------*\n");
                    }
                    for_num = 0;
                }
            }
            if (for_num == 0) {
                free(buf2);
            } else {
                all[i].num = atoi(buf2);
                free(buf2);
                error2 = 0;
            }
            for_num = 1;
            count = 0;
        }
        error2 = 1;
    }
}

// put by index
P *put_by_index(P *all, P *st_buffer, int *len, int index) {
    int new_len = *len;
    all = realloc(all, (*len + 1) * (sizeof(P)));
    while (new_len > index) {
        strcpy(all[new_len].n, all[new_len - 1].n);
        all[new_len].str = all[new_len - 1].str;
        all[new_len].num = all[new_len - 1].num;
        new_len -= 1;
    }
    all[index] = st_buffer[0];
    *len += 1;
    return all;
}

// free structures memory
void free_mem_struct(P *all, int len) {
    if (len != 0) {
        for (int i = 0; i < len; i++) {
            free(all[i].str);
        }
        free(all);
    }
}

// output array element by element
void print_str_array(P *all, int len) {
    printf("*----------------------------------------------------*\n");
    printf("|                     Your array                     |\n");
    printf("*----------------------------------------------------*\n");
    int space_str = 22;
    int space_num = 5;
    for (int i = 0; i < len; i++){
        if (space_str <= strlen(all[i].str) + 2){
        space_str = strlen(all[i].str) + 2;
        }
        if (space_num <= count_of_num(all[i].num)){
            space_num = count_of_num(all[i].num);
        }
    }
    for (int i = 0; i < len; i++) {
        if (i < 10) {
            printf("%d:    |  %s  |  %s", i, all[i].n, all[i].str);
        }
        if (i >= 10 && i < 100) {
            printf("%d:   |  %s  |  %s", i, all[i].n, all[i].str);
        }
        if (i >= 100 && i < 1000) {
            printf("%d:  |  %s  |  %s", i, all[i].n, all[i].str);
        }
        if (i >= 1000 && i < 10000) {
            printf("%d: |  %s  |  %s", i, all[i].n, all[i].str);
        }
        if (i >= 10000 && i < 100000) {
            printf("%d:  |  %s  |  %s", i, all[i].n, all[i].str);
        }
        if (i >= 100000 && i < 1000000) {
            printf("%d:  |  %s  |  %s", i, all[i].n, all[i].str);
        }
        for (int j = 0; j <= space_str - strlen(all[i].str); j++) {
            printf(" ");
        }
        printf("| %d", all[i].num);
        int buf = all[i].num;
        int k = count_of_num(buf);
        for (int j = 0; j <= space_num - k; j++) {
            printf(" ");
        }
        printf("|\n");
    }
}

// delete by index and length
P *delete_by_indexes(P *all, int *len) {
    int right, interval;
    char *s;
    printf("Print index:\n");
    s = get_str();
    right = s_choose(s);
    if (right == -1) {
        return all;
    }
    if (right >= *len || right < 0) {
        printf("*----------------------------------------------------*\n");
        printf("       !  ERROR : Invalid index or interval  !\n");
        printf("*----------------------------------------------------*\n");
        return all;
    }
    printf("print LEN:\n");
    scanf("%d", &interval);
    scanf("%*c");
    if (right + interval > *len || interval <= 0) {
        printf("*----------------------------------------------------*\n");
        printf("      !  ERROR : Invalid index or interval  !\n");
        printf("*----------------------------------------------------*\n");
        return all;
    }
    int start = interval + right;
    for (int j = right; j < start; j++) {
        free(all[j].str);
    }
    while (start <= *len - 1) {
        strcpy(all[start - interval].n, all[start].n);
        all[start - interval].str = all[start].str;
        all[start - interval].num = all[start].num;
        start += 1;
    }
    all = realloc(all, (*len - interval) * (sizeof(P)));
    *len = *len - interval;
    return all;
}

// string input
char *get_str() {
    char buf[81] = {0};
    char *res = NULL;
    int len = 0;
    int n = 0;
    do {
        n = scanf("%80[^\n]", buf);
        if (n < 0) {
            if (!res) {
                return NULL;
            }
        } else if (n > 0) {
            int chunk_len = (int) strlen(buf);
            int str_len = len + chunk_len;
            res = realloc(res, str_len + 1);
            memcpy(res + len, buf, chunk_len);
            len = str_len;
        } else {
            scanf("%*c");
        }
    } while (n > 0);

    if (len > 0) {
        res[len] = '\0';
    } else {
        res = calloc(1, sizeof(char));
    }
    return res;
}

// put element in sorted array
P *put_in_sorted(P *all, P *st_buffer, int *len, int size, int field) {
    int k = 0;
    for (int i = 0; i < *len; i++) {
        if (field == 3) {
            if (all[i].num > st_buffer[0].num) {
                k += 1;
                all = put_by_index(all, st_buffer, len, i);
                break;
            }
        } else if (field == 2) {
            if (strcmp(all[i].str, st_buffer[0].str) > 0) {
                k += 1;
                all = put_by_index(all, st_buffer, len, i);
                break;
            }
        } else if (field == 1) {
            if (strcmp(all[i].n, st_buffer[0].n) > 0) {
                k += 1;
                all = put_by_index(all, st_buffer, len, i);
                break;
            }
        }
    }
    if (k == 0) {
        all = put_by_index(all, st_buffer, len, *len);
    }
    return all;
}

//pseudo-random generation of structs fields
void write_str_array_random(P *all, int len) {
    char *buffer1;
    for (int i = 0; i < len; i++) {
        int n = rand() % 20;
        buffer1 = calloc(n + 1, sizeof(char));
        for (int j = 0; j < n; j++) {
            char k = (char) ((rand() % 58) + 65);
            buffer1[j] = k;
        }
        for (int j = 0; j < 8; j++) {
            char k = (char) ((rand() % 58) + 65);
            all[i].n[j] = k;
        }
        all[i].str = buffer1;
        all[i].num = rand() % 1000000;
    }
}

//count of num
int count_of_num(int buf){
    int k = 0;
    if (buf == 0){
        return 1;
    }
    while (buf != 0){
        buf /= 10;
        k ++;
    }
    return k;
}