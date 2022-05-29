#ifndef UNTITLED2_FILE_STRUCT_H
#define UNTITLED2_FILE_STRUCT_H

char *get_str_file(FILE *);

void structure_input_file(FILE *, P *, int);

int is_structure_from_file_ok(FILE *);

void write_str_array_file(P *, int, FILE *);

#endif //UNTITLED2_FILE_STRUCT_H
