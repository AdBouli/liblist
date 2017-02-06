#ifndef ARRAY_H
#define ARRAY_H

/**
 * @brief Structure du tableau
 */
typedef struct array* Array;

/**
 * @brief Type du tableau
 */
typedef int data_type;

/**
 * @brief Créer la structure tableau
 * @param capacity - Capacité du tableau à créer
 */
Array array_create (int capacity);

/**
 * @brief Libère l'espace mémoire du tableau
 */
void array_destroy (Array table);

/**
 * @brief Copie le tableau
 * @return Copie du tableau
 */
Array array_copy (Array table);

/**
 * @brief Donne la taille actuelle du tableau
 * @return Taille du tableau
 */
int array_size (Array table);

/**
 * @brief Donne la capacité du tableau
 * @return Capacité du tableau
 */
int array_capacity (Array table);

/**
 * @brief Test si le tableau est vide
 * @return Vrai si le tableau est vide
 */
bool array_is_empty (Array table);

/**
 * @brief Ajoute une valeur à la fin du tableau
 * @param value - Valeur à ajouter
 */
void array_append (Array table, data_type value);

/**
 * @brief Ajoute une valeur à la position donnée
 * @param value - Valeur à ajouter
 * @param indice - Position où insérer la nouvelle valeur
 */
void array_append_at (Array table, data_type value, int indice);

/**
 * @biref Remplace une valeur par une autre
 * @param value - Valeur de remplacement
 * @param indice - Position de la valeur à remplacée
 */
void array_replace_at (Array table, data_type value, int indice);

/**
 * @brief Donne la valeur à la position donnée
 * @param indice - Position de la valeur
 * @return La valeur
 */
data_type array_value_at (Array table, int indice);

/**
 * @brief Supprime la dernière valeur du tableau
 */
void array_delete_last (Array table);

/**
 * @brief Supprime la valeur à la position donnée
 * @param indice - Position de la valeur à supprimer
 */
void array_delete_at (Array table, int indice);

/**
 * @brief Supprime toutes les occurences de la valeur donnée
 * @param value - Valeur à supprimer
 */
void array_delete_all_occurences (Array table, data_type val);

/**
 * @brief Vide le tableau
 */
void array_delete_all(Array table);

/**
 * @brief Décale les valeurs du tableau
 * @param start - Position du début du décalage
 * @param end - Position de la fin du décalage
 * @param shift - Nombre de décalage (>0 : droite, <0 : gauche)
 */
void array_shift (Array table, int start, int end, int shift);

/**
 * @brief Fusionne table_1 et table_2
 * @return Fusion de table_1 et table_2
 */
Array array_merge (Array table_1, Array table_2);

/**
 * @brief Concatenne table_1 et table_2
 * @return Concatennation de table_1 et table_2
 */
Array array_concat (Array table_1, Array table_2);

/**
 * @brief Trie le tableau
 */
void array_sort (Array table);

/**
 * @brief Recherche une valeur dans le tableau
 * @param value - Valeur à chercher
 * @return Position de la valeur recherchée (-1 dans le cas echeant)
 */
int array_search (Array table, data_type value);

/**
 * @brief Recherche une valeur dans le tableau trie
 * @param value - Valeur à chercher
 * @return Position de la valeur recherchée (-1 dans le cas echeant)
 */
int array_dsearch (Array table, data_type value);

/**
 * @brief Affiche le tableau
 */
void array_print (Array table);

#endif /* ARRAY_H */
