#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <readline/readline.h>

char *func(char *, const char *, const char *);

char change_sym(char);

int d_or_not(char, const char *);

int main() {
    char *s = NULL;
    char *new_str;
    printf("Enter divide words symbols:\n");
    char *dws = readline("");
    printf("Enter divide sentences symbols:\n");
    char *dss = readline("");
    do {
        printf("Enter your sentence:\n");
        s = readline("");
        if (s) {
            new_str = func(s, dws, dss);
            if (*new_str) {
                printf("%s\n", new_str);
            }
            free(s);
            free(new_str);
        }
    } while (s);
    free(dws);
    free(dss);
    return 0;
}

char *func(char *s, const char *dws, const char *dss) {
    char *copy_of_s = calloc(strlen(s) + 1, sizeof(char));
    strcpy(copy_of_s, s);
    char *new_str = calloc(strlen(s) + strlen(s) / 2 + 2, sizeof(char));
    char *tok, *tok2;
    char *ptr, *ptr2;
    int k = 1;
    int a = 0;
    int b = 0;
    for (tok = strtok_r(copy_of_s, dss, &ptr); tok != NULL; tok = strtok_r(NULL, dss, &ptr)) {
        a += (int) strlen(tok);
        for (tok2 = strtok_r(tok, dws, &ptr2); tok2 != NULL; tok2 = strtok_r(NULL, dws, &ptr2)) {
            if (k == 1) {
                strcat(new_str, tok2);
                k = 0;
            } else {
                strcat(new_str, " ");
                strcat(new_str, tok2);
            }
        }
        if (a + 1 <= strlen(s)) {
            if (a + 3 <= strlen(s)) {
                if (s[a] == s[a + 1]) {
                    strncat(new_str, s + a, 3);
                    a += 3;
                } else {
                    strncat(new_str, s + a, 1);
                    a += 1;
                }
            } else if (d_or_not(s[a], dss)) {
                strncat(new_str, s + a, 1);
                a += 1;
            }
            strcat(new_str, "\n");
        }
        new_str[b] = change_sym(new_str[b]);
        b = (int) strlen(new_str);
        k = 1;
    }
    if (strlen(new_str) > 0) {
        if (new_str[strlen(new_str) - 1] == '\n') {
            new_str[strlen(new_str) - 1] = '\0';
        }
    }
    free(copy_of_s);
    return new_str;
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
