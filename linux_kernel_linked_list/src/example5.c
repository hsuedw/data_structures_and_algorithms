#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*
 * Add several nodes into the doubly linked list.
 * Then traverse all the nodes.
 */

struct test {
    int value;
    struct list_head node;
};

struct test *create_node(int value)
{
    struct test *pdata = calloc(1, sizeof(struct test));
    pdata->value = value;
    INIT_LIST_HEAD(&pdata->node);

    return pdata;
}

#define LIST_SZ (5)

int main(int argc, char *argv[])
{
    struct list_head *head = calloc(1, sizeof(struct list_head));
    INIT_LIST_HEAD(head);

    for (int i = 0; i < LIST_SZ; ++i) {
        struct test *new_data = create_node(i);
	list_add_tail(&new_data->node, head);
    }
    /* Now, the doubly linked list has following nodes: 0 1 2 3 4 */

    printf("List all the data in the doubly linked list: ");
    struct test *it = NULL;
    list_for_each_entry(it, head, node) {
        printf("%d ", it->value);
    }
    printf("\n");

    printf("Delete the first node from the doubly linked list.\n");
    struct list_head *x = head->next;
    list_del_init(x);
    free(container_of(x, struct test, node));
    /* Now, the doubly linked list has following nodes: 1 2 3 4 */

    printf("List the rest data in the doubly linked list: ");
    list_for_each_entry(it, head, node) {
        printf("%d ", it->value);
    }
    printf("\n");

    printf("Delete the node at the tail of the doubly linked list.\n");
    x = head->prev;
    list_del_init(x);
    free(container_of(x, struct test, node));
    /* Now, the doubly linked list has following nodes: 1 2 3 */

    printf("List the rest data in the doubly linked list: ");
    list_for_each_entry(it, head, node) {
        printf("%d ", it->value);
    }
    printf("\n");

    printf("Delete the whole doubly linked list.\n");
    struct test *it2 = NULL;
    list_for_each_entry_safe(it, it2, head, node) {
        list_del_init(&it->node);
	free(it);
    }
    if (list_empty(head)) {
        printf("All the data have been deleted from the doubly linked list.\n");
    }
    free(head);

    return 0;
}
