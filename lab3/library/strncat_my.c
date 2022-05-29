#include "strlen_my.h"
void strncat_my(char *to_str, const char *from_str, int count) {
    size_t i = strlen_my(to_str);
    for (size_t j = 0; j < count; j++) {
        *(to_str + i + j) = *(from_str + j);
    }
}
