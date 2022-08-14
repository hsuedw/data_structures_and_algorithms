#include <stdio.h>
#include "list.h"

/*
 * Add several nodes the tail of the doubly linked list.
 */

int main(int argc, char *argv[])
{
    LIST_HEAD(head);

    LIST_HEAD(node1);
    list_add_tail(&node1, &head);

    LIST_HEAD(node2);
    list_add_tail(&node2, &head);

    LIST_HEAD(node3);
    list_add_tail(&node3, &head);

    /*
     * Now, the doubly linked list is head <-> node1 <-> node2 <-> node3
     *                                 ^                            ^
     *                                 |____________________________|
     */
    
    return 0;
}
