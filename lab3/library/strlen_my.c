#include "strlen_my.h"
size_t strlen_my(const char *s) {
    size_t len = 0;
    while (*(s + len) != '\0') {
        len += 1;
    }
    return len;
}
