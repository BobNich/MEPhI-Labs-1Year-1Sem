#include <stdio.h>
#include <stdlib.h>
#include "string_my.h"

char *get_str();

char *func(char *, const char *, const char *);

char change_sym(char);

int d_or_not(char, const char *);

int main() {
    char *s = NULL;
    char *new_str;
    printf("Enter divide words symbols:\n");
    char *dws = get_str();
    printf("Enter divide sentences symbols:\n");
    char *dss = get_str();
    do {
        printf("Enter your sentence:\n");
        s = get_str();
        if (s) {
            new_str = func(s, dws, dss);
            if (*new_str) {
                printf("%s\n", new_str)
            }
            free(s);
            fre(new_str);
        }
    } while (s);
    free(dws);
    free(dss);
    return 0;
}

char *func(char *s, const char *dws, const char *dss) {
    char *copy_of_s = calloc(strlen_my(s) + 1, sizeof(char));
    strcpy_my(copy_of_s, s);
    char *new_str = calloc(strlen_my(s) + strlen_my(s) / 2 + 2, sizeof(char));
    char *tok, *tok2;
    char *ptr, *ptr2;
    /* the first word in sentence - k = 1 , else k = 0 */
    int k = 1;
    int a = 0;
    int b = 0;
    /* dividing string into other strings and words */
    for (tok = strtok_r(copy_of_s, dss, &ptr); tok != NULL; tok = strtok_r(NULL, dss, &ptr)) {
        a += (int) strlen(tok);
        for (tok2 = strtok_r(tok, dws, &ptr2); tok2 != NULL; tok2 = strtok_r(NULL, dws, &ptr2)) {
            if (k == 1) {
                strcat_my(new_str, tok2);
                k = 0;
            } else {
                strcat_my(new_str, " ");
                strcat_my(new_str, tok2);
            }
        }
        /* end symbol */
        if (a + 1 <= strlen_my(s)) {
            if (a + 3 <= strlen_my(s)) {
                if (s[a] == s[a + 1]) {
                    strncat_my(new_str, s + a, 3);
                    a += 3;
                } else {
                    strncat_my(new_str, s + a, 1);
                    a += 1;
                }
            } else if (d_or_not(s[a], dss)) {
                strncat_my(new_str, s + a, 1);
                a += 1;
            }
            strcat_my(new_str, "\n");
        }
        /* changing the first letter in sentence */
        new_str[b] = change_sym(new_str[b]);
        b = (int) strlen_my(new_str);
        k = 1;
    }
    /* checking if the last symbol is '\n' */
    if (strlen_my(new_str) > 0) {
        if (new_str[strlen_my(new_str) - 1] == '\n') {
            new_str[strlen_my(new_str) - 1] = '\0';
        }
    }
    free(copy_of_s);
    return new_str;
}

char *get_str() {
    char buf[81] = {0};
    char *res = NULL;
    int len = 0;
    int n = 0;
    do {
        n = scanf("%80[^\n]", buf);
        if (n < 0) {
            if (!res) {
                return NULL;
            }
        } else if (n > 0) {
            int chunk_len = (int) strlen_my(buf);
            int str_len = len + chunk_len;
            res = realloc(res, str_len + 1);
            memcpy_my(res + len, buf, chunk_len);
            len = str_len;
        } else {
            scanf("%*c");
        }
    } while (n > 0);

    if (len > 0) {
        res[len] = '\0';
    } else {
        res = calloc(1, sizeof(char));
    }
    return res;
}

char change_sym(char ss) {
    int a = (int) ss;
    if (a >= 'a' && a <= 'z') {
        ss = (char) (a - ('a' - 'A'));
    }
    return ss;
}

int d_or_not(char k, const char *dss) {
    int t = 0;
    int i = 0;
    while (dss[i]) {
        if (dss[i] == k)
            t = 1;
        i++;
    }
    return t;
}
