#ifndef UNTITLED2_STRUCT_TRANSF_H
#define UNTITLED2_STRUCT_TRANSF_H

typedef struct {
    char n[9];
    char *str;
    int num;
} P;

void structure_input(P *, int);

P *delete_by_indexes(P *, int *);

P *put_by_index(P *, P *, int *, int);

P *put_in_sorted(P *, P *, int *, int, int);

void print_str_array(P *, int);

void write_str_array_random(P *, int);

void free_mem_struct(P *, int);

char *get_str();

int count_of_num(int);

#endif //UNTITLED2_STRUCT_TRANSF_H
