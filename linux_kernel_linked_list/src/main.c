#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char *argv[])
{
    struct list_head *head = calloc(1, sizeof(struct list_head));
    INIT_LIST_HEAD(head);

    struct list_head *node1 = calloc(1, sizeof(struct list_head));
    INIT_LIST_HEAD(node1);
    printf("node1: %p\n", node1);
 
    struct list_head *node2 = calloc(1, sizeof(struct list_head));
    INIT_LIST_HEAD(node2);
    printf("node2: %p\n", node2);
   
    struct list_head *node3 = calloc(1, sizeof(struct list_head));
    INIT_LIST_HEAD(node3);
    printf("node3: %p\n", node3);

    list_add(node1, head);
    list_add(node2, head);
    list_add(node3, head);
    struct list_head *it = NULL;
    list_for_each(it, head) {
        printf("%p ", it);
    }
    printf("\n");

    return 0;
}
