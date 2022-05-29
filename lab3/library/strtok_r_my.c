#include "string_my.h"
char *strtok_r_my(char *s, const char *divide, char **save_ptr) {
    char *next_ptr;
    if (s == NULL)
        s = *save_ptr;
    if (*s == '\0') {
        *save_ptr = s;
        return NULL;
    }
    s += strspn_my(s, divide);
    if (*s == '\0') {
        *save_ptr = s;
        return NULL;
    }
    next_ptr = s + strcspn_my(s, divide);
    if (*next_ptr == '\0') {
        *save_ptr = next_ptr;
        return s;
    }
    *next_ptr = '\0';
    *save_ptr = next_ptr + 1;
    return s;
}

