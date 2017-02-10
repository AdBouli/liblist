#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "slist.h"
#include "slist_func.h"

SList slist_delete_all_occurences (SList list, data_type data)
{
    if (list == NULL)
    {
        return NULL;
    }
    if (slist_data(list) == data)
    {
        SList next = slist_next(list);
        slist_free(list);
        return slist_delete_all_occurences(next, data);
    }
    else
    {
        data_type tmp_data = slist_data(list);
        SList next = slist_next(list);
        slist_free(list);
        return slist_prepend(slist_delete_all_occurences(next, data), tmp_data);
    }
}

int slist_length (SList list)
{
    if (list == NULL)
    {
        return 0;
    }
    SList next = slist_next(list);
    if (next == NULL)
    {
        return 1;
    }
    return 1 + slist_length(next);
}

SList slist_copy (SList list)
{
    if (list == NULL)
    {
        return NULL;
    }
    if (slist_next(list) == NULL)
    {
        return slist_prepend(NULL, slist_data(list));
    }
    return slist_prepend(slist_copy(slist_next(list)), slist_data(list));
}

SList slist_append (SList list, data_type data)
{
    if (list == NULL)
    {
        return slist_prepend(list, data);
    }
    SList p = list;
    while (slist_next(p) != NULL)
    {
        p = slist_next(p);
    }
    return slist_insert_after(list, p, data);
}

SList slist_reverse (SList list)
{
    if (list == NULL)
    {
        return NULL;
    }
    if (slist_next(list) == NULL)
    {
        return list;
    }
    data_type data = slist_data(list);
    SList next = slist_next(list);
    slist_free(list);
    return slist_append(slist_reverse(next), data);
}

SList slist_concat (SList list_1, SList list_2)
{
    if (list_2 == NULL)
    {
        return list_1;
    }
    list_1 = slist_append(list_1, slist_data(list_2));
    if (slist_next(list_2) != NULL)
    {
        list_1 = slist_concat(list_1, slist_next(list_2));
    }
    return list_1;
}

SList slist_last (SList list)
{
    assert(list);
    if (slist_next(list) == NULL)
    {
        return list;
    }
    return slist_last(slist_next(list));
}

SList slist_nth (SList list, int n)
{
    assert(list);
    if (n == 0 || list == NULL)
    {
        return NULL;
    }
    if (n == 1)
    {
        return list;
    }
    return slist_nth(slist_next(list), n - 1);
}

data_type slist_nth_data (SList list, int n)
{
    assert(list);
    if (n == 1)
    {
        return slist_data(list);
    }
    return slist_nth_data(slist_next(list), n - 1);
}

SList slist_find (SList list, data_type data)
{
    if (list == NULL)
    {
        return NULL;
    }
    if (slist_data(list) == data)
    {
        return list;
    }
    return slist_find(slist_next(list), data);
}

int slist_position (SList list, SList p)
{
    if (list == NULL)
    {
        return -1;
    }
    if (list == p)
    {
        return 1;
    }
    int pos = slist_position(slist_next(list), p);
    if (pos < 0)
    {
        return -1;
    }
    else
    {
        return 1 + pos;
    }
}

int slist_index (SList list, data_type data)
{
    if (list == NULL)
    {
        return -1;
    }
    if (slist_data(list) == data)
    {
        return 1;
    }
    int index = slist_index(slist_next(list), data);
    if (index < 0)
    {
        return -1;
    }
    else
    {
        return 1 + index;
    }
}

void slist_print (SList list)
{
    if (list != NULL)
    {
        printf(" %d ", slist_data(list));
        SList next = slist_next(list);
        if (next != NULL)
        {
            slist_print(next);
        }
        else
        {
            printf("\n");
        }
    }
    else
    {
        printf("Liste vide.\n");
    }
}
