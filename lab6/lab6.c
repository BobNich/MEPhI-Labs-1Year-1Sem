#include <stdio.h>
#include <time.h>
#include "list_lab6.h"

int main() {
    Node *list = NULL;
    clock_t start, end;
    do {
        printf("Print your string:\n");
        list = createList();
        if (!list) {
            break;
        }
        start = clock();
        list = delete_spaces(list);
        list = reverse_letters(list);
        end = clock();
        double time = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Total time - %.15lf\n", time);
        printList(list);
        freeList(list);
    } while (1);
    return 0;
}

