#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dlist.h"

struct dlist
{
	struct dlist* previous;
	data_type data;
	struct dlist* next;
};

DList dlist_create ()
{
	return NULL;
}

DList dlist_alloc ()
{
	DList p = (DList) malloc(sizeof(struct dlist));
	if (p == NULL)
	{
		fprintf(stderr, "Erreur d'allocation memoire: dlist_alloc\n");
		exit(EXIT_FAILURE);
	}
	p->previous = NULL;
	p->next = NULL;
	return NULL;
}

void dlist_free (DList list)
{
	if (list != NULL)
	{
		free(list);
	}
}

void dlist_destroy (DList list)
{
	DList next;
	while (list != NULL)
	{
		next = list->next;
		free(list);
		list = next;
	}
}

DList dlist_prepend (DList list, data_type data)
{
	DList p = dlist_alloc();
	p->data = data;
	p->next = list;
	if (list != NULL)
	{
		list->previous = p;
	}
	return p;
}

DList dlist_delete_first (DList list)
{
	if (list != NULL)
	{
		DList next = list->next;
		dlist_free(list);
		list = next;
		list->previous = NULL;
	}
	return list;
}

DList dlist_insert_after (DList list, DList p, data_type data)
{
	if (p != NULL)
	{
		DList next = p->next;
		DList new = dlist_alloc();
		new->data = data;
		new->previous = p;
		p->next = new;
		new->next = next;
		if (next != NULL)
		{
			next->previous = new;
		}
	}
	return list;
}

DList dlist_delete_after (DList list, DList p)
{
	if (p != NULL)
	{
		if (p->next != NULL)
		{
			DList to_delete = p->next;
			p->next = to_delete->next;
			if (to_delete->next != NULL)
			{
				to_delete->next->previous = p;
			}
			dlist_free(to_delete);
		}
	}
	return list;
}

DList dlsit_insert_before (DList list, DList p, data_type data)
{
	if (p != NULL)
	{
		DList previous = p->previous;
		if (previous == NULL)
		{
			return dlist_prepend(list, data);
		}
		DList new = dlist_alloc();
		new->data = data;
		previous->next = new;
		new->previous = previous;
		new->next = p;
		p->previous = new;
	}
	return list;
}

DList dlist_delete_before (DList list, DList p)
{
	if (p != NULL)
	{
		DList to_delete = p->previous;
		if (to_delete != NULL)
		{
			DList previous = to_delete->previous;
			p->previous = previous;
			if (previous != NULL)
			{
				previous->next = p;
			}
			else
			{
				list = p;
			}
			dlist_free(to_delete);
		}
	}
	return list;
}

DList dlist_next (DList list)
{
	assert(list);
	return list->next;
}

DList dlist_prev (DList list)
{
	assert(list);
	return list->previous;
}

data_type dlist_data (DList list)
{
	assert(list);
	return list->data;
}

bool dlist_is_empty (DList list)
{
	return (list == NULL);
}
