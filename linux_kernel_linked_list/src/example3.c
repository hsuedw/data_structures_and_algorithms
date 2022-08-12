#include <stdio.h>
#include "list.h"

/*
 * Add several nodes into the doubly linked list.
 * Then traverse all the nodes.
 */

struct test_list {
    int value;
    struct list_head node;
};

void init_node(struct test_list *n, int v)
{
    INIT_LIST_HEAD(&n->node);
    n->value = v;
}

int main(int argc, char *argv[])
{
    LIST_HEAD(head);

    /* Add data1 at the head of the doubly linked list */
    struct test_list data1;
    init_node(&data1, 1);
    list_add(&data1.node, &head);

    /* Add data2 at the head of the doubly linked list */
    struct test_list data2;
    init_node(&data2, 2);
    list_add(&data2.node, &head);

    /* Add data3 at the head of the doubly linked list */
    struct test_list data3;
    init_node(&data3, 3);
    list_add(&data3.node, &head);

    /* Add data4 at the tail of the doubly linked list */
    struct test_list data4;
    init_node(&data4, 4);
    list_add_tail(&data4.node, &head);

    /* Add data5 at the tail of the doubly linked list */
    struct test_list data5;
    init_node(&data5, 5);
    list_add_tail(&data5.node, &head);

    /* Add data6 at the tail of the doubly linked list */
    struct test_list data6;
    init_node(&data6, 6);
    list_add_tail(&data6.node, &head);

    /*
     * Now, the doubly linked list is "head <-> 3 <-> 2 <-> 1 <-> 4 <-> 5 <-> 6".
     */

    struct test_list *it = NULL;
    list_for_each_entry(it, &head, node) {
        printf(" %d ", it->value);
    }
    printf("\n");
    
    return 0;
}
