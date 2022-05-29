#include "strlen_my.h"
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