#include "strlen_my.h"
void strcpy_my(char *copy, const char *old) {
    size_t len_of_new = strlen_my(old) + 1;
    for (size_t i = 0; i < len_of_new; i++) {
        *(copy + i) = *(old + i);
    }
}
