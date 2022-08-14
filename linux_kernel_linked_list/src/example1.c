#include <stdio.h>
#include "list.h"

/*
 * Add several nodes right after the head of the doubly linked list.
 */

int main(int argc, char *argv[])
{
    LIST_HEAD(head);

    LIST_HEAD(node1);
    list_add(&node1, &head);

    LIST_HEAD(node2);
    list_add(&node2, &head);

    LIST_HEAD(node3);
    list_add(&node3, &head);

    /*
     * Now, the doubly linked list is head <-> node3 <-> node2 <-> node1
     *                                  ^                            ^
     *                                  |____________________________|
     */
    
    return 0;
}
