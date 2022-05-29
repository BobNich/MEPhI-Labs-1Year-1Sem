#ifndef UNTITLED2_MATRIX_CHANGE_H
#define UNTITLED2_MATRIX_CHANGE_H

char *get_str();

void input_matrix(int **, int, int);

void print_matrix(int **, int, int);

void free_matrix(int **, int, int);

int ** matrix_random(int **, int, int);

int ** insert_column_matrix(int ** ,int *, int *, int *, int);

int ** insert_row_matrix(int ** ,int *, int *, int *, int);

int ** delete_row_matrix(int ** , int *, int *, int);

int ** delete_column_matrix(int ** , int *, int *, int);

int ** matrix_times_vector(int ** ,int *, int *, int *);

int * insert_buffer(int);

#endif //UNTITLED2_MATRIX_CHANGE_H
