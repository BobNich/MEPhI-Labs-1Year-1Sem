#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct_transf.h"
#include "file_struct.h"
#include "errors_lab4.h"

//check if struct is OK
int is_structure_from_file_ok(FILE *file) {
    int status = 1;
    char *buf_check1;
    char *buf_check;
    char *buf_check2;
    char *f = get_str_file(file);
    int len;
    len = s_choose1(f);
    if (len == -1){
        status = 0;
    }
    for (int i = 0; i < len; i++) {
        buf_check1 = get_str_file(file);
        if (strlen(buf_check1) != 8) {
            printf("*----------------------------------------------------*\n");
            printf("         !    ERROR : %d.n is incorrect    !        \n", i);
            printf("*----------------------------------------------------*\n");
            status = 0;
        }
        buf_check2 = get_str_file(file);
        buf_check = get_str_file(file);
        for (int j = 0; j < strlen(buf_check); j++) {
            if (!(buf_check[j] >= '0' && buf_check[j] <= '9')) {
                printf("*----------------------------------------------------*\n");
                printf("         !    ERROR : %d.num is incorrect    !        \n", i);
                printf("*----------------------------------------------------*\n");
                status = 0;
            }
        }
        free(buf_check2);
        free(buf_check1);
        free(buf_check);
    }
    fclose(file);
    return status;
}

//getting array from file
void structure_input_file(FILE *file, P *all, int len) {
    for (int i = 0; i < len; i++) {
        char *buf = get_str_file(file);
        strcpy(all[i].n, buf);
        free(buf);
        all[i].str = get_str_file(file);
        char *f = get_str_file(file);
        all[i].num = (int) atoi(f);
        free(f);
    }
}

//write array into file
void write_str_array_file(P *all, int len, FILE *file_struct) {
    fprintf(file_struct, "%d\n", len);
    for (int i = 0; i < len; i++) {
        fprintf(file_struct, "%s\n", all[i].n);
        fprintf(file_struct, "%s\n", all[i].str);
        fprintf(file_struct, "%d\n", all[i].num);
    }
    fclose(file_struct);
    printf("File saved!\n");
}

// getting struct element from file, dynamically
char *get_str_file(FILE *file) {
    char buf[81] = {0};
    char *res = NULL;
    int len = 0;
    int n = 0;
    do {
        n = fscanf(file, "%80[^\n]", buf);
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
            fscanf(file, "%*c");
        }
    } while (n > 0);

    if (len > 0) {
        res[len] = '\0';
    } else {
        res = calloc(1, sizeof(char));
    }
    return res;
}

