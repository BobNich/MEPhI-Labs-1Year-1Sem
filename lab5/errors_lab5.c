#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errors_lab5.h"

int len_error(int len){
    if (len <= 0) {
        printf("*----------------------------------------------------*\n");
        printf("|   !   ERROR : Invalid num of rows or columns   !   |\n");
        printf("*----------------------------------------------------*\n");
        return 1;
    }
    return 0;
}

double s_choose(char *s){
    double choice = 0.5;
    if (strlen(s) == 0){
        free(s);
        return choice;
    }
    for (int i = 0; i < strlen(s); i++){
        if (i == 0 && s[0] == '-'){
        }
        else if (!(s[i]>= '0' && s[i] <= '9')){
            choice = 0.5;
            free(s);
            return choice;
        }
    }
    choice = atoi(s);
    free(s);
    return choice;
}

void error1(){
    printf("*----------------------------------------------------*\n");
    printf("            !    ERROR : Invalid value    !           \n");
    printf("*----------------------------------------------------*\n");
}