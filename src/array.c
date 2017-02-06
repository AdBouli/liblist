#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "array.h"

/**
 * @brief Structure du tableau dynamique
 * tab: Le tableau
 * capacity: Capacité du tableau (mémoire allouée)
 * size: Taille du tableau (nombre de case)
 */
struct array
{
	data_type* tab;
	int size;
	int capacity;
};


Array array_create (int capacity)
{
	assert(capacity > 0);
	Array table = (Array) malloc(sizeof(struct array));
	if (table == NULL)
	{
		fprintf(stderr, "Erreur allocation mémoire: array_create\n");
		exit(EXIT_FAILURE);
	}
	table->capacity = capacity;
	table->size = 0;
	table->tab = (data_type*) malloc(capacity * sizeof(data_type));
	if (table->tab == NULL)
	{
		fprintf(stderr, "Erreur allocation mémoire: array_create\n");
		exit(EXIT_FAILURE);
	}
	return table;
}

void array_destroy (Array table)
{
	assert(table);
	if (table->tab == NULL)
	{
		free(table);
		return;
	}
	free(table->tab);
	free(table);
}

Array array_copy (Array table)
{
	assert(table);
	assert(table->size >= 0);
	assert(table->capacity > 0);
	Array copy = array_create(table->capacity);
	copy->size = table->size;
	for (int i = 0; i < table->size; i++)
	{
		copy->tab[i] = table->tab[i];
	}
	return copy;
}

int array_size (Array table)
{
	assert(table);
	return table->size;
}

int array_capacity (Array table)
{
	assert(table);
	return table->capacity;
}

bool array_is_empty (Array table)
{
	assert(table);
	return (table->size == 0);
}

void array_extend (Array table)
{
	assert(table);
	table->capacity *= 2;
	table->tab = (data_type*) realloc(table->tab, table->capacity * sizeof(data_type));
	if (table->tab == NULL)
	{
		fprintf(stderr, "Erreur allocation mémoire: array_extend\n");
		exit(EXIT_FAILURE);
	}
}

void array_append (Array table, data_type value)
{
	assert(table);
	if (table->size == table->capacity)
	{
		array_extend(table);
	}
	table->tab[table->size++] = value;
}

void array_append_at (Array table, data_type value, int indice)
{
	assert(table);
	assert(indice >= 0);
	assert(indice < table->size);
	array_shift(table, indice, table->size - 1, 1);
	table->tab[indice] = value;
}

void array_replace_at (Array table, data_type value, int indice)
{
	assert(table);
	assert(indice >= 0);
	assert(indice < table->size);
	table->tab[indice] = value;
}

data_type array_value_at (Array table, int indice)
{
	assert(table);
	assert(indice >= 0);
	assert(indice < table->size);
	return table->tab[indice];
}

void array_delete_last (Array table)
{
	assert(table);
	table->size--;
}

void array_delete_at (Array table, int indice)
{
	assert(table);
	assert(indice >= 0);
	assert(indice < table->size);
	if (indice != table->size - 1)
	{
		array_shift(table, indice + 1, table->size - 1, -1);
	}
	table->size--;
}

void array_delete_all_occurences (Array table, data_type val)
{
	assert(table);
	for (int i = 0; i < table->size; i++)
	{
		if (val == array_value_at(table, i))
		{
			array_delete_at(table, i);
			i--;
		}
	}
}

void array_delete_all(Array table)
{
	assert(table);
	table->size = 0;
}

void array_shift (Array table, int start, int end, int shift)
{
	assert(table);
	assert(start >= 0);
	assert(start < table->size);
	assert(end >= 0);
	assert(end < table->size);
	while (table->size + shift >= table->capacity)
	{ // Tant que la capacité est trop petite
		array_extend(table);
	}
	if (shift > 0)
	{ // Si décalage vers la droite
		if (end + shift >= table->size)
		{ // Si décalage hors tableau
			table->size = end + shift + 1;
		}
		for (int i = end; i >= start; i--)
		{
			table->tab[i + shift] = table->tab[i];
		}
	}
	else if (shift < 0)
	{ // Si décalage vers la gauche
		for (int i = start; i <= end; i++)
		{
			if (i + shift >= 0)
			{ // Si décalage dans tableau
				table->tab[i + shift] = table->tab[i];
			}
		}
	}
}

Array array_merge (Array table_1, Array table_2)
{
	assert(table_1);
	assert(table_2);
	Array new = array_create(table_1->capacity + table_2->capacity);
	new->size = table_1->size + table_2->size;
	int i1 = 0;
	int i2 = 0;
	int n = 0;
	while (i1 < table_1->size && i2 < table_2->size)
	{
		if (table_1->tab[i1] <= table_2->tab[i2])
		{
			new->tab[n++] = table_1->tab[i1++];
		}
		else
		{
			new->tab[n++] = table_2->tab[i2++];
		}
	}
	if (i1 < table_1->size)
	{
		for (int i = i1; i < table_1->size; i++)
		{
			new->tab[n++] = table_1->tab[i];
		}
	}
	if (i2 < table_2->size)
	{
		for (int i = i2; i < table_2->size; i++)
		{
			new->tab[n++] = table_2->tab[i];
		}
	}
	return new;
}

Array array_concat (Array table_1, Array table_2)
{
	assert(table_1);
	assert(table_2);
	Array new = array_create(table_1->capacity + table_2->capacity);
	new->size = table_1->size + table_2->size;
	int n = 0;
	for (int i = 0; i < table_1->size; i++)
	{
		new->tab[n++] = table_1->tab[i];
	}
	for (int i = 0; i < table_2->size; i++)
	{
		new->tab[n++] = table_2->tab[i];
	}
	return new;
}

void array_sort_aux_2 (Array table, int start, int middle, int stop)
{
	data_type aux[table->size];
	int i = start;
	int j = middle + 1;
	int k = 0;
	while (i <= middle && j <= stop)
	{
		if (table->tab[i] <= table->tab[j])
		{
			aux[k++] = table->tab[i++];
		}
		else
		{
			aux[k++] = table->tab[j++];
		}
	}
	while (i <= middle)
	{
		aux[k++] = table->tab[i++];
	}
	while (j <= stop)
	{
		aux[k++] = table->tab[j++];
	}
	while (--k >= 0)
	{
		table->tab[start+k] = aux[k];
	}
}

void array_sort_aux_1 (Array table, int start, int stop)
{
	if (start < stop)
	{
		int middle = (start + stop) / 2;
		array_sort_aux_1(table, start, middle);
		array_sort_aux_1(table, middle + 1, stop);
		array_sort_aux_2(table, start, middle, stop);
	}
}

void array_sort (Array table)
{
	assert(table);
	array_sort_aux_1(table, 0, table->size - 1);
}

int array_search (Array table, data_type value)
{
	assert(table);
	for (int i = 0; i < table->size; i++)
	{
		if (table->tab[i] == value)
		{
			return i;
		}
	}
	return -1;
}

int array_dsearch_aux(Array table, data_type value, int start, int stop)
{
	if (start > stop)
	{
		return -1;
	}
	int middle = (start + stop) / 2;
	if (table->tab[middle] > value)
	{
		return array_dsearch_aux(table, value, start, middle - 1);
	}
	if (table->tab[middle] < value)
	{
		return array_dsearch_aux(table, value, middle + 1, stop);
	}
	if (table->tab[middle] == value)
	{
		return middle;
	}
	return -1;
}

int array_dsearch(Array table, data_type value)
{
	assert(table);
	return array_dsearch_aux(table, value, 0, table->size - 1);
}

void array_print (Array table)
{
	for (int i = 0; i < table->size; i++)
	{
		printf("%4d -> %9d", i, table->tab[i]);
		if (i % 4 == 3)
		{
			printf("\n");
		}
		else
		{
			printf("%3c", '|');
		}
	}
	printf("\n");
}
