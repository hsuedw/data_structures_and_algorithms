#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define LIST_LEN (10)

struct node_data {
    int val;
    struct list_head node;
};

struct node_data *new_node_data(int val)
{
    struct node_data *new = (struct node_data *) calloc(1, sizeof(struct node_data));
    new->val = val;
    INIT_LIST_HEAD(&new->node);

    return new;
}

int main(int argc, char *argv[])
{
    LIST_HEAD(head);

    /* Add data into the list */
    struct node_data *data = NULL;
    for (int i = 0; i < LIST_LEN; ++i) {
        data = new_node_data(i);
	list_add(&data->node, &head);
    }

    /* Print the list */
    struct node_data *it = NULL;
    list_for_each_entry(it, &head, node) {
        printf("%d ", it->val);
    }
    printf("\n");

    /* Delete the list */
    struct node_data *it2 = NULL;
    list_for_each_entry_safe(it, it2, &head, node) {
        list_del(&it->node);
	free(it);
    }

    /* ---------------------------- */

    /* Add data into the list */
    for (int i = 0; i < LIST_LEN; ++i) {
        data = new_node_data(i);
	list_add_tail(&data->node, &head);
    }

    /* Print the list */
    list_for_each_entry(it, &head, node) {
        printf("%d ", it->val);
    }
    printf("\n");

    /* Delete the list */
    list_for_each_entry_safe(it, it2, &head, node) {
        list_del(&it->node);
	free(it);
    }

    return 0;
}
