#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "errors_lab5.h"
#include "matrix_change.h"
#include "matrix_file.h"

int main() {
    FILE * file;
    char * name_of_file;
    srand(time(NULL));
    char *s;
    int choice;
    int index;
    int ** matrix;
    int * inserted_array;
    int rows = 0;
    int columns = 0;
    double buf;
    do {
        printf("*----------------------------------------------------*\n");
        printf("|                        Menu                        |\n");
        printf("*----------------------------------------------------*\n");
        printf("|   1 - Input matrix                                 |\n");
        printf("|   2 - Insert row into matrix by index              |\n");
        printf("|   3 - Insert column into matrix by index           |\n");
        printf("|   4 - Delete row from matrix by index              |\n");
        printf("|   5 - Delete column from matrix by index           |\n");
        printf("|   6 - Random matrix generation                     |\n");
        printf("|   7 - Input matrix from file                       |\n");
        printf("|   8 - Write matrix into file                       |\n");
        printf("|   9 - Product of a matrix by a vector              |\n");
        printf("|  10 - Print matrix                                 |\n");
        printf("*----------------------------------------------------*\n");
        printf("|   0 - Quit menu                                    |\n");
        printf("*----------------------------------------------------*\n");
        printf("                    Your choice                       \n");
        s = get_str();
        buf = s_choose(s);
        if (buf != 0.5){
            choice = (int) buf;
        }
        else{
            choice = -1;
        }
        switch (choice) {

            //Input matrix
            case 1:
                free_matrix(matrix, rows, columns);
                printf("Enter the number of raws of matrix:\n");
                s = get_str();
                buf = s_choose(s);
                if (buf == 0.5 || buf <= 0){
                    columns = 0;
                    rows = 0;
                    error1();
                    break;
                }
                rows = (int) buf;
                printf("Enter the number of columns of matrix:\n");
                s = get_str();
                buf = s_choose(s);
                if (buf == 0.5 || buf <= 0){
                    columns = 0;
                    rows = 0;
                    error1();
                    break;
                }
                columns = (int) buf;
                matrix = (int ** )malloc(rows * sizeof (int *));
                for (int i = 0; i < rows ;i++){
                    matrix[i] = (int *) malloc( columns * sizeof (int));
                }
                input_matrix(matrix, rows, columns);
                break;

            //Insert row into matrix by index
            case 2:
                if (len_error(rows) || len_error(columns)){
                    break;
                }
                printf("Print index\n");
                s = get_str();
                buf = s_choose(s);
                if (buf == 0.5){
                    error1();
                    break;
                }
                index = (int) buf;
                if (index > rows || index < 0){
                    error1();
                    break;
                }
                inserted_array = insert_buffer(columns);
                matrix = insert_row_matrix(matrix, inserted_array, &rows, &columns, index);
                break;

            //Insert column into matrix by index
            case 3:
                if (len_error(rows) || len_error(columns)){
                    break;
                }
                printf("Print index\n");
                s = get_str();
                buf = s_choose(s);
                if (buf == 0.5){
                    error1();
                    break;
                }
                index = (int) buf;
                if (index > columns || index < 0){
                    error1();
                    break;
                }
                inserted_array = insert_buffer(rows);
                insert_column_matrix(matrix, inserted_array, &rows, &columns, index);
                break;

             //Delete row from matrix by index
            case 4:
                if (len_error(rows) || len_error(columns)){
                    break;
                }
                printf("Print index\n");
                s = get_str();
                buf = s_choose(s);
                if (buf == 0.5){
                    error1();
                    break;
                }
                index = (int) buf;
                if (index >= rows || index < 0){
                    error1();
                    break;
                }
                matrix = delete_row_matrix(matrix, &rows, &columns, index);
                break;

            //Delete column from matrix by index
            case 5:
                if (len_error(rows) || len_error(columns)){
                    break;
                }
                printf("Print index\n");
                s = get_str();
                buf = s_choose(s);
                if (buf == 0.5){
                    error1();
                    break;
                }
                index = (int) buf;
                if (index >= columns || index < 0){
                    error1();
                    break;
                }
                matrix = delete_column_matrix(matrix, &rows, &columns, index);
                break;

            //Random matrix generation
            case 6:
                free_matrix(matrix, rows, columns);
                printf("Enter the number of raws of matrix:\n");
                s = get_str();
                buf = s_choose(s);
                if (buf == 0.5){
                    error1();
                    columns = 0;
                    rows = 0;
                    break;
                };
                rows = (int) buf;
                if (rows < 0){
                    error1();
                    columns = 0;
                    rows = 0;
                    break;
                }
                printf("Enter the number of columns of matrix:\n");
                s = get_str();
                buf = s_choose(s);
                if (buf == 0.5){
                    error1();
                    columns = 0;
                    rows = 0;
                    break;
                }
                columns = (int) buf;
                if (columns < 0){
                    error1();
                    columns = 0;
                    rows = 0;
                    break;
                }
                matrix = (int ** )malloc(rows * sizeof (int *));
                for (int i = 0; i < rows ;i++){
                    matrix[i] = (int *) malloc( columns * sizeof (int));
                }
                matrix = matrix_random(matrix, rows, columns);
                break;

            //Input matrix from file
            case 7:
                printf("Print name of file:\n");
                name_of_file = get_str();
                if (!(file = fopen(name_of_file, "rb"))) {
                    printf("*----------------------------------------------------*\n");
                    printf("         !  ERROR : Invalid name of file  !           \n");
                    printf("*----------------------------------------------------*\n");
                    free(name_of_file);
                    break;
                }
                free_matrix(matrix, rows, columns);
                matrix = input_from_bin_file_matrix(file, &rows, &columns);
                free(name_of_file);
                break;

            //Write matrix into file
            case 8:
                if (len_error(rows) || len_error(columns)){
                    break;
                }
                printf("Print name of file:\n");
                name_of_file = get_str();
                if (!(file = fopen(name_of_file, "wb"))){
                    printf("*----------------------------------------------------*\n");
                    printf("         !  ERROR : Invalid name of file  !           \n");
                    printf("*----------------------------------------------------*\n");
                    fclose(file);
                    free(name_of_file);
                    break;
                }
                write_matrix_bin_file(matrix, rows, columns, file);
                free(name_of_file);
                break;

            //Product of a matrix by a vector
            case 9:
                if (len_error(rows + columns)){
                    break;
                }
                inserted_array = insert_buffer(columns);
                matrix = matrix_times_vector(matrix, inserted_array, &rows, &columns);
                break;

            //Print matrix
            case 10:
                if (len_error(rows) || len_error(columns)){
                    break;
                }
                print_matrix(matrix, rows, columns);
                break;
            default:
                break;
        }
    } while (choice);
    free_matrix(matrix, rows, columns);
    printf("*----------------------------------------------------*\n");
    printf("|        Bye bye, my friend! See you soon ;)         |\n");
    printf("*----------------------------------------------------*\n");
    return 0;
}
