#include <stddef.h>
#include "string_my.h"

size_t strlen_my(const char *s) {
    int len = 0;
    while (*(s + len) != '\0') {
        len += 1;
    }
    return len;
}

void strcpy_my(char *copy, const char *old) {
    size_t len_of_new = strlen_my(old) + 1;
    for (size_t i = 0; i < len_of_new; i++) {
        *(copy + i) = *(old + i);
    }
}

void strcat_my(char *to_str, const char *from_str) {
    size_t i = strlen_my(to_str);
    for (size_t j = 0; *(from_str + j) != '\0'; j++) {
        *(to_str + i + j) = *(from_str + j);
    }
}

void strncat_my(char *to_str, const char *from_str, int count) {
    size_t i = strlen_my(to_str);
    for (size_t j = 0; j < count; j++) {
        *(to_str + i + j) = *(from_str + j);
    }
}

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

void memcpy_my(char *s_to, const char *s_from, int n) {
    for (size_t i = 0; i < n; i++) {
        *(s_to + i) = *(s_from + i);
    }
}

size_t strspn_my(const char *s, const char *s_find) {
    size_t k = 0, h = 0;
    for (size_t i = 0; i < strlen_my(s); i++) {
        for (size_t j = 0; j < strlen_my(s_find); j++) {
            if (*(s + i) == *(s_find + j)) {
                k += 1;
                break;
            }
        }
        if (k > 0) {
            h += 1;
            k = 0;
        } else {
            return h;
        }
    }
    return h;
}

size_t strcspn_my(const char *s, const char *s_find) {
    size_t k = 0, h = 0;
    for (size_t i = 0; i < strlen_my(s); i++) {
        for (size_t j = 0; j < strlen_my(s_find); j++) {
            if (*(s + i) == *(s_find + j)) {
                k += 1;
                break;
            }
        }
        if (k == 0) {
            h += 1;
            k = 0;
        } else {
            return h;
        }
    }
    return h;
}
