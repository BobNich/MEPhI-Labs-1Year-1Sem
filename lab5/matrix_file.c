#include <stdio.h>
#include <stdlib.h>
#include "matrix_file.h"

void write_matrix_bin_file(int **matrix, int rows, int columns, FILE *file) {
    fwrite(&rows, sizeof(int), 1, file);
    fwrite(&columns, sizeof(int), 1, file);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            fwrite(&matrix[i][j], sizeof(int), 1, file);
        }
    }
    fclose(file);
}

int **input_from_bin_file_matrix(FILE *file, int * rows_1, int * columns_1) {
    int rows = 0;
    int columns = 0;
    fread(&rows, sizeof(int), 1, file);
    fread(&columns, sizeof(int), 1, file);
    int **matrix = (int **) malloc(rows * sizeof(int *));\
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *) malloc(columns * sizeof(int));
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            fread(&matrix[i][j], sizeof(int), 1, file);
        }
    }
    *rows_1 = rows;
    *columns_1 = columns;
    fclose(file);
    return matrix;
}

