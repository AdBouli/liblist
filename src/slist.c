#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "slist.h"

struct slist
{
    data_type data;
    struct slist* next;
};

SList slist_create ()
{
    return NULL;
}

SList slist_alloc ()
{
    SList p = (SList) malloc(sizeof(struct slist));
    if (p == NULL)
    {
        fprintf(stderr, "Erreur allocation mémoire: slist_alloc\n");
        exit(EXIT_FAILURE);
    }
    p->next = NULL;
    return p;
}

void slist_free (SList list)
{
    if (list != NULL)
    {
        free(list);
    }
}

void slist_destroy (SList list)
{
    SList next;
    while (list != NULL)
    {
        next = list->next;
        free(list);
        list = next;
    }
}

SList slist_prepend (SList list, data_type data)
{
    SList p = slist_alloc();
    p->data = data;
    p->next = list;
    return p;
}

SList slist_delete_first (SList list)
{
    if (list != NULL)
    {
        SList next = list->next;
        slist_free(list);
        list = next;
    }
    return list;
}

SList slist_insert_after (SList list, SList p, data_type data)
{
    if (p != NULL)
    {
        SList new = slist_alloc();
        new->data = data;
        new->next = p->next;
        p->next = new;
    }
    return list;
}

SList slist_delete_after (SList list, SList p)
{
    if (p != NULL && p->next != NULL)
    {
        SList to_delete = p->next;
        p->next = to_delete->next;
        slist_free(to_delete);
    }
    return list;
}

SList slist_next (SList list)
{
    assert(list);
    return list->next;
}

data_type slist_data (SList list)
{
    assert(list);
    return list->data;
}

bool slist_is_empty (SList list)
{
    return (list == NULL);
}
