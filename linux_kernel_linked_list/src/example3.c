#include <stdio.h>
#include "list.h"

/*
 * Add several nodes into the doubly linked list.
 * Then traverse all the nodes.
 */

int main(int argc, char *argv[])
{
    LIST_HEAD(head);

    /* Add node1 at the head of the doubly linked list */
    LIST_HEAD(node1);
    printf("node1: 0x%p\n", &node1);
    list_add(&node1, &head);

    /* Add node2 at the head of the doubly linked list */
    LIST_HEAD(node2);
    printf("node2: 0x%p\n", &node2);
    list_add(&node2, &head);

    /* Add node3 at the tail of the doubly linked list */
    LIST_HEAD(node3);
    printf("node3: 0x%p\n", &node3);
    list_add_tail(&node3, &head);

    /* Add node4 at the tail of the doubly linked list */
    LIST_HEAD(node4);
    printf("node4: 0x%p\n", &node4);
    list_add_tail(&node4, &head);

    /*
     * Now, the doubly linked list is "head <-> node2 <-> node1 <-> node3 <-> node4".
     *                                  ^                                       ^
     *                                  |_______________________________________|
     */

    struct list_head *it = NULL;
    printf("list_for_each: ");
    list_for_each(it, &head) {
        printf("0x%p ", it);
    }
    printf("\n");
 
    it = NULL;
    printf("list_for_each_prev: ");
    list_for_each_prev(it, &head) {
        printf("0x%p ", it);
    }
    printf("\n");
   
    return 0;
}
