#include <stdio.h>
#include "list.h"

/*
 * Add several nodes right after the head of the doubly linked list.
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

    struct test_list data1;
    init_node(&data1, 1);
    list_add(&data1.node, &head);

    struct test_list data2;
    init_node(&data2, 2);
    list_add(&data2.node, &head);

    struct test_list data3;
    init_node(&data3, 3);
    list_add(&data3.node, &head);

    /*
     * Now, the doubly linked list is "head <-> 3 <-> 2 <-> 1".
     */

    struct test_list *it = NULL;
    list_for_each_entry(it, &head, node) {
        printf(" %d ", it->value);
    }
    printf("\n");
    
    return 0;
}
