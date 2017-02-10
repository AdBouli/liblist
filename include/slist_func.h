#ifndef SLIST_FUNC_H
#define SLIST_FUNC_H

#include "slist.h"

SList slist_delete_all_occurences (SList list, data_type data);

int slist_length (SList list);

SList slist_copy (SList list);

SList slist_append (SList list, data_type data);

SList slist_reverse (SList list);

SList slist_concat (SList list_1, SList list_2);

SList slist_last (SList list);

SList slist_nth (SList list, int n);

data_type slist_nth_data (SList list, int n);

SList slist_find (SList list, data_type data);

int slist_position (SList list, SList p);

int slist_index (SList list, data_type data);

void slist_print (SList list);

#endif /* SLIST_FUNC_H */
