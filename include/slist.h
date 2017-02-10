#ifndef SLIST_H
#define SLIST_H

/**
 * @brief Structure de la liste
 */
typedef struct slist* SList;

/**
 * @brief Type de la liste
 */
typedef int data_type;

SList slist_create ();

void slist_free (SList list);

void slist_destroy (SList list);

SList slist_prepend (SList list, data_type value);

SList slist_delete_first (SList list);

SList slist_insert_after (SList list, SList p, data_type value);

SList slist_delete_after (SList list, SList p);

SList slist_next (SList list);

data_type slist_value (SList list);

bool slist_is_empty (SList list);

#endif /* SLIST_H */
