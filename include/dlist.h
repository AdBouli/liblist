#ifndef SLIST_H
#define SLIST_H

/**
 * @brief Structure de la liste
 */
typedef struct dlist* DList;

/**
 * @brief Type de la liste
 */
typedef int data_type;

DList dlist_create ();

void dlist_free ();

void dlist_destroy ();

DList dlist_prepend (DList list, data_type data);

DList dlist_delete_first (DList list);

DList dlist_insert_after (DList list, DList p, data_type data);

DList dlist_delete_after (DList list, DList p);

DList dlsit_insert_before (DList list, DList p, data_type data);

DList dlist_delete_before (DList list, DList p);

DList dlist_next (DList list);

DList dlist_prev (DList list);

data_type dlist_data (DList list);

bool dlist_is_empty (DList list);

#endif /* SLIST_H */
