#include "strlen_my.h"
void strcat_my(char *to_str, const char *from_str) {
    size_t i = strlen_my(to_str);
    for (size_t j = 0; *(from_str + j) != '\0'; j++) {
        *(to_str + i + j) = *(from_str + j);
    }
}
