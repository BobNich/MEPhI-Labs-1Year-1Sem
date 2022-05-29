#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix_change.h"
#include "errors_lab5.h"

int *insert_buffer(int len){
    int error = 1;
    double buf;
    char *s;
    int *insertion_array = calloc(len, sizeof(int));
    for (int i = 0; i < len; i++){
        printf("Print element\n");
        while (error) {
            s = get_str();
            buf = s_choose(s);
            if (buf == 0.5){
                printf("Repeat, value is invalid\n");
                error = 1;
            }
            else{
                insertion_array[i] = (int) buf;
                error = 0;
            }
        }
        error = 1;
    }
    return insertion_array;
}

void print_matrix(int **matrix, int rows, int columns){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

void input_matrix(int **matrix, int rows, int columns){
    double buf;
    char *s;
    int error = 1;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            printf("Print element\n");
            while (error) {
                s = get_str();
                buf = s_choose(s);
                if (buf == 0.5){
                    printf("Repeat, value is invalid\n");
                    error = 1;
                }
                else{
                    matrix[i][j] = (int) buf;
                    error = 0;
                }
            }
            error = 1;
        }
    }
}

void free_matrix(int ** matrix, int rows, int columns){
    if (rows + columns != 0){
        for (int i = 0; i < rows; i++){
            free(matrix[i]);
        }
        free(matrix);
    }
}

int ** matrix_random(int ** matrix, int rows, int columns){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            matrix[i][j] = rand() % 10000;
        }
    }
    return matrix;
}



int ** insert_row_matrix(int ** matrix,int * insert_buffer, int *rows, int *columns, int index){
    int new_row = *rows;
    *rows += 1;
    matrix = (int **) realloc(matrix, (*rows) * sizeof(int *));
    matrix[*rows -  1] = (int *) malloc( (*columns) * sizeof(int));
    while (new_row > index){
        for (int i = 0; i < *columns; i++){
            matrix[new_row][i] = matrix[new_row - 1][i];
        }
        new_row -= 1;
    }
    for (int i = 0; i < *columns; i++){
        matrix[index][i] = insert_buffer[i];
    }
    free(insert_buffer);
    return matrix;
}

int ** insert_column_matrix(int ** matrix,int * insert_buffer, int *rows, int *columns, int index){
    int new_columns = *columns;
    int new2_columns = new_columns;
    *columns += 1;
    for (int i = 0; i < *rows; i++){
        matrix[i] = (int *) realloc(matrix[i],(*columns) * sizeof (int));
        while (new_columns > index){
            matrix[i][new_columns] = matrix[i][new_columns - 1];
            new_columns -= 1;
        }
        new_columns = new2_columns;
        matrix[i][index] = insert_buffer[i];
    }
    free(insert_buffer);
    return matrix;
}

int ** delete_row_matrix(int ** matrix, int *rows, int *columns, int index){
    int new_row = index + 1;
    free(matrix[index]);
    matrix[index] = (int *) malloc( (*columns) * sizeof(int));
    for (int i = index + 1; i < *rows; i++){
        for (int j = 0; j < *columns; j++){
            matrix[new_row - 1][j] = matrix[new_row][j];
        }
        new_row +=1;
    }
    free(matrix[*rows - 1]);
    *rows -= 1;
    matrix = (int **) realloc(matrix, (*rows) * sizeof(int *));
    return matrix;
}

int ** delete_column_matrix(int ** matrix, int *rows, int *columns, int index){
    for (int i = 0; i < *rows; i++){
        for (int j = index + 1; j < *columns; j++){
            matrix[i][j - 1] = matrix[i][j];
        }
        matrix[i] = realloc(matrix[i], (*columns - 1) *sizeof (int));
    }
    *columns -= 1;
    return matrix;
}

int ** matrix_times_vector(int ** matrix, int * insert_buffer, int *rows, int *columns){
    int sum = 0;
    int ** new_matrix = (int **) malloc(*rows * sizeof(int *));
    for (int i = 0; i < *rows ;i++){
        new_matrix[i] = (int *) malloc( 1 * sizeof(int));
    }
    for (int i = 0; i < *rows; i++){
        for (int j = 0; j < *columns; j++){
            sum += matrix[i][j] * insert_buffer[j];
        }
        new_matrix[i][0] = sum;
        sum = 0;
    }
    free_matrix(matrix, *rows, *columns);
    free(insert_buffer);
    *columns = 1;
    return new_matrix;
}

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
