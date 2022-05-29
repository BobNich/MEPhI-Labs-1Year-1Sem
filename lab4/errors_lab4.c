#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int s_choose(char *s){
    int choice;
    if (strlen(s) == 0){
        printf("*----------------------------------------------------*\n");
        printf("            !    ERROR : Invalid value    !            \n");
        printf("*----------------------------------------------------*\n");
        choice = -1;
        free(s);
        return choice;
    }
        for (int i = 0; i < strlen(s); i++){
            if (!(s[i]>= '0' && s[i] <= '9')){
                printf("*----------------------------------------------------*\n");
                printf("            !    ERROR : Invalid value    !            \n");
                printf("*----------------------------------------------------*\n");
                choice = -1;
                free(s);
                return choice;
            }
        }
        choice = atoi(s);
        free(s);
    return choice;
}

int len_error(int len){
    if (len <= 0) {
        printf("*----------------------------------------------------*\n");
        printf("           !    ERROR : Invalid len     !              \n");
        printf("*----------------------------------------------------*\n");
        return 1;
    }
    return 0;
}

int s_choose1(char *s){
    int choice;
    for (int i = 0; i < strlen(s); i++){
        if (!(s[i]>= '0' && s[i] <= '9')){
            printf("*----------------------------------------------------*\n");
            printf("     !    ERROR : Invalid first value in file    !    \n");
            printf("*----------------------------------------------------*\n");
            choice = -1;
            free(s);
            return choice;
        }
    }
    choice = atoi(s);
    free(s);
    return choice;
}
