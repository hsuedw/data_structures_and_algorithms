#include <stdio.h>
#include "list.h"

/*
 * Add several nodes into the doubly linked list.
 * Then traverse all the nodes.
 */

struct test {
    int value;
    struct list_head node;
};

void init_list_node(struct test *pdata, int value)
{
    pdata->value = value;
    INIT_LIST_HEAD(&pdata->node);
}

int main(int argc, char *argv[])
{
    LIST_HEAD(head);

    /* Add data1 at the head of the doubly linked list */
    struct test data1;
    init_list_node(&data1, 1);
    list_add(&data1.node, &head);

    /* Add data2 at the head of the doubly linked list */
    struct test data2;
    init_list_node(&data2, 2);
    list_add(&data2.node, &head);

    /* Add data3 at the tail of the doubly linked list */
    struct test data3;
    init_list_node(&data3, 3);
    list_add_tail(&data3.node, &head);

    /* Add data4 at the tail of the doubly linked list */
    struct test data4;
    init_list_node(&data4, 4);
    list_add_tail(&data4.node, &head);

    /*
     * Now, the doubly linked list is "head <-> node2 <-> node1 <-> node3 <-> node4".
     *                                  ^                                       ^
     *                                  |_______________________________________|
     */

    struct test *it = NULL;
    printf("list_for_each_entry: ");
    list_for_each_entry(it, &head, node) {
        printf("%d ", it->value);
    }
    printf("\n");
 
    it = NULL;
    printf("list_for_each_entry_reverse: ");
    list_for_each_entry_reverse(it, &head, node) {
        printf("%d ", it->value);
    }
    printf("\n");

    return 0;
}
