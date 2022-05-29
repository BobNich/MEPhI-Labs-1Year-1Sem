#include <stddef.h>
#include "string.h"

size_t strlen(const char *s) {
    size_t len = 0;
    while (*(s + len) != '\0') {
        len += 1;
    }
    return len;
}

void strcpy(char *copy, const char *old) {
    size_t len_of_new = strlen(old) + 1;
    for (size_t i = 0; i < len_of_new; i++) {
        *(copy + i) = *(old + i);
    }
}

void strcat(char *to_str, const char *from_str) {
    size_t i = strlen(to_str);
    for (size_t j = 0; *(from_str + j) != '\0'; j++) {
        *(to_str + i + j) = *(from_str + j);
    }
}

void strncat(char *to_str, const char *from_str, int count) {
    size_t i = strlen(to_str);
    for (size_t j = 0; j < count; j++) {
        *(to_str + i + j) = *(from_str + j);
    }
}

char *strtok_r(char *s, const char *divide, char **save_ptr) {
    char *next_ptr;
    if (s == NULL)
        s = *save_ptr;
    if (*s == '\0') {
        *save_ptr = s;
        return NULL;
    }
    s += strspn(s, divide);
    if (*s == '\0') {
        *save_ptr = s;
        return NULL;
    }
    next_ptr = s + strcspn(s, divide);
    if (*next_ptr == '\0') {
        *save_ptr = next_ptr;
        return s;
    }
    *next_ptr = '\0';
    *save_ptr = next_ptr + 1;
    return s;
}

void memcpy(char *s_to, const char *s_from, int n) {
    for (size_t i = 0; i < n; i++) {
        *(s_to + i) = *(s_from + i);
    }
}

size_t strspn(const char *s, const char *s_find) {
    size_t k = 0, h = 0;
    for (size_t i = 0; i < strlen(s); i++) {
        for (size_t j = 0; j < strlen(s_find); j++) {
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

size_t strcspn(const char *s, const char *s_find) {
    size_t k = 0, h = 0;
    for (size_t i = 0; i < strlen(s); i++) {
        for (size_t j = 0; j < strlen(s_find); j++) {
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
