#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "test_toolbox.h"
#include "array.h"

bool test_array_create ()
{
	bool result = true;

	Array test = array_create(10);

	result = test_equality_int(0, array_size(test), "array_create(10): size != 0") && result;
	result = test_equality_int(10, array_capacity(test), "array_create(10): capacity != 10") && result;

	array_destroy(test);

	return result;
}

bool test_array_copy ()
{
	bool result = true;

	Array test = array_create(10);

	array_append(test, 0);
	array_append(test, 1);
	array_append(test, 1);
	array_append(test, 2);
	array_append(test, 3);
	array_append(test, 5);
	array_append(test, 8);
	// 0 1 1 2 3 5 8

	Array copy_test = array_copy(test);
	result = test_equality_int(array_size(test), array_size(copy_test), "array_copy: size t1 != size t2") && result;
	result = test_equality_int(array_capacity(test), array_capacity(copy_test), "array_copy: capacity t1 != capacity t2") && result;
	result = test_equality_int(array_value_at(test, 0), array_value_at(copy_test, 0), "array_copy: t1[0] != t2[0]") && result;
	result = test_equality_int(array_value_at(test, 1), array_value_at(copy_test, 1), "array_copy: t1[1] != t2[1]") && result;
	result = test_equality_int(array_value_at(test, 2), array_value_at(copy_test, 2), "array_copy: t1[2] != t2[2]") && result;
	result = test_equality_int(array_value_at(test, 3), array_value_at(copy_test, 3), "array_copy: t1[3] != t2[3]") && result;
	result = test_equality_int(array_value_at(test, 4), array_value_at(copy_test, 4), "array_copy: t1[4] != t2[4]") && result;
	result = test_equality_int(array_value_at(test, 5), array_value_at(copy_test, 5), "array_copy: t1[5] != t2[5]") && result;
	result = test_equality_int(array_value_at(test, 6), array_value_at(copy_test, 6), "array_copy: t1[6] != t2[6]") && result;

	array_destroy(copy_test);
	array_destroy(test);

	return result;
}

bool test_array_size ()
{
	bool result = true;

	Array test = array_create(5);

	result = test_equality_int(0, array_size(test), "array_size: size != 0");
	array_append(test, 1);
	// 1
	result = test_equality_int(1, array_size(test), "array_size: size != 1");
	array_append(test, 1);
	// 1 1
	result = test_equality_int(2, array_size(test), "array_size: size != 2");
	array_delete_all(test);
	//
	result = test_equality_int(0, array_size(test), "array_size: size != 0");

	array_destroy(test);

	return result;
}

bool test_array_capacity ()
{
	bool result = true;

	Array test = array_create(2);

	result = test_equality_int(2, array_capacity(test), "array_capacity: capacity != 2");
	array_append(test, 1);
	// 1
	result = test_equality_int(2, array_capacity(test), "array_capacity: capacity != 2");
	array_append(test, 1);
	// 1 1
	result = test_equality_int(2, array_capacity(test), "array_capacity: capacity != 2");
	array_append(test, 1);
	// 1 1 1
	result = test_equality_int(4, array_capacity(test), "array_capacity: capacity != 4");

	array_destroy(test);

	return result;
}

bool test_array_is_empty ()
{
	bool result = true;

	Array test = array_create(5);

	result = test_equality_bool(true, array_is_empty(test), "array_is_empty: not true") && result;
	array_append(test, 1);
	result = test_equality_bool(false, array_is_empty(test), "array_is_empty: not false") && result;
	array_delete_all(test);
	result = test_equality_bool(true, array_is_empty(test), "array_is_empty: not true") && result;

	array_destroy(test);

	return result;
}

bool test_array_append ()
{
	bool result = true;

	Array test = array_create(5);

	array_append(test, 2);
	// 2
	result = test_equality_int(2, array_value_at(test, 0), "array_append(t, 2): t[0] != 2") && result;
	result = test_equality_int(1, array_size(test), "array_append(t, 2): size != 1") && result;

	array_append(test, 3);
	// 2 3
	result = test_equality_int(3, array_value_at(test, 1), "array_append(t, 3): t[1] != 3") && result;
	result = test_equality_int(2, array_size(test), "array_append(t, 3): size != 2") && result;

	array_append(test, 5);
	// 2 3 5
	result = test_equality_int(5, array_value_at(test, 2), "array_append(t, 5): t[2] != 5") && result;
	result = test_equality_int(3, array_size(test), "array_append(t, 5): size != 3") && result;

	array_append(test, 7);
	// 2 3 5 7
	result = test_equality_int(7, array_value_at(test, 3), "array_append(t, 7: t[3] != 7") && result;
	result = test_equality_int(4, array_size(test), "array_append(t, 7: size != 4") && result;

	array_append(test, 11);
	// 2 3 5 7 11
	result = test_equality_int(11, array_value_at(test, 4), "array_append(t, 11): t[4] != 11") && result;
	result = test_equality_int(5, array_size(test), "array_append(t, 11): size != 5") && result;

	array_append(test, 13);
	// 2 3 5 7 11 13
	result = test_equality_int(13, array_value_at(test, 5), "array_append(t, 13): t[5] != 13") && result;
	result = test_equality_int(6, array_size(test), "array_append(t, 13): size != 6") && result;
	result = test_equality_int(10, array_capacity(test), "array_append(t, 13): capacity != 10") && result;

	array_destroy(test);

	return result;
}

bool test_array_append_at ()
{
	bool result = true;

	Array test = array_create(10);
	array_append(test, 2);
	array_append(test, 3);
	array_append(test, 5);
	array_append(test, 7);
	array_append(test, 11);
	array_append(test, 13);
	// 2 3 5 7 11 13

	array_append_at(test, 4, 2);
	// 2 3 4 5 7 11 13
	result = test_equality_int(7, array_size(test), "array_append_at(t, 4, 2): size != 7") && result;
	result = test_equality_int(2, array_value_at(test, 0), "array_append_at(t, 4, 2): t[0] != 2") && result;
	result = test_equality_int(3, array_value_at(test, 1), "array_append_at(t, 4, 2): t[1] != 3") && result;
	result = test_equality_int(4, array_value_at(test, 2), "array_append_at(t, 4, 2): t[2] != 4") && result;
	result = test_equality_int(5, array_value_at(test, 3), "array_append_at(t, 4, 2): t[3] != 5") && result;
	result = test_equality_int(7, array_value_at(test, 4), "array_append_at(t, 4, 2): t[4] != 7") && result;
	result = test_equality_int(11, array_value_at(test, 5), "array_append_at(t, 4, 2): t[5] != 11") && result;
	result = test_equality_int(13, array_value_at(test, 6), "array_append_at(t, 4, 2): t[6] != 13") && result;

	array_append_at(test, 1, 0);
	// 1 2 3 4 5 7 11 13
	result = test_equality_int(8, array_size(test), "array_append_at(t, 1, 0): size != 8") && result;
	result = test_equality_int(1, array_value_at(test, 0), "array_append_at(t, 1, 0): t[0] != 1") && result;
	result = test_equality_int(2, array_value_at(test, 1), "array_append_at(t, 1, 0): t[1] != 2") && result;
	result = test_equality_int(3, array_value_at(test, 2), "array_append_at(t, 1, 0): t[2] != 3") && result;
	result = test_equality_int(4, array_value_at(test, 3), "array_append_at(t, 1, 0): t[3] != 4") && result;
	result = test_equality_int(5, array_value_at(test, 4), "array_append_at(t, 1, 0): t[4] != 5") && result;
	result = test_equality_int(7, array_value_at(test, 5), "array_append_at(t, 1, 0): t[5] != 7") && result;
	result = test_equality_int(11, array_value_at(test, 6), "array_append_at(t, 1, 0): t[6] != 11") && result;
	result = test_equality_int(13, array_value_at(test, 7), "array_append_at(t, 1, 0): t[7] != 13") && result;

	array_destroy(test);

	return result;
}

bool test_array_replace_at ()
{
	bool result = true;

	Array test = array_create(10);
	array_append(test, 2);
	array_append(test, 3);
	array_append(test, 5);
	array_append(test, 7);
	array_append(test, 11);
	array_append(test, 13);
	// 2 3 5 7 11 13

	array_replace_at(test, 6, 2);
	// 2 3 6 7 11 13
	result = test_equality_int(2, array_value_at(test, 0), "array_replace_at(t, 6, 2): t[0] != 2") && result;
	result = test_equality_int(3, array_value_at(test, 1), "array_replace_at(t, 6, 2): t[1] != 3") && result;
	result = test_equality_int(6, array_value_at(test, 2), "array_replace_at(t, 6, 2): t[2] != 6") && result;
	result = test_equality_int(7, array_value_at(test, 3), "array_replace_at(t, 6, 2): t[3] != 7") && result;
	result = test_equality_int(11, array_value_at(test, 4), "array_replace_at(t, 6, 2): t[4] != 11") && result;
	result = test_equality_int(13, array_value_at(test, 5), "array_replace_at(t, 6, 2): t[5] != 13") && result;

	array_replace_at(test, 20, 5);
	// 2 3 6 7 11 20
	result = test_equality_int(2, array_value_at(test, 0), "array_replace_at(t, 20, 5): t[0] != 2") && result;
	result = test_equality_int(3, array_value_at(test, 1), "array_replace_at(t, 20, 5): t[1] != 3") && result;
	result = test_equality_int(6, array_value_at(test, 2), "array_replace_at(t, 20, 5): t[2] != 6") && result;
	result = test_equality_int(7, array_value_at(test, 3), "array_replace_at(t, 20, 5): t[3] != 7") && result;
	result = test_equality_int(11, array_value_at(test, 4), "array_replace_at(t, 20, 5): t[4] != 11") && result;
	result = test_equality_int(20, array_value_at(test, 5), "array_replace_at(t, 20, 5): t[5] != 20") && result;

	array_destroy(test);

	return result;
}

bool test_array_value_at ()
{
	bool result = true;

	Array test = array_create(10);
	array_append(test, 2);
	array_append(test, 3);
	array_append(test, 5);
	array_append(test, 7);
	array_append(test, 11);
	array_append(test, 13);
	// 2 3 5 7 11 13

	result = test_equality_int(2, array_value_at(test, 0), "array_value_at(t, 0): t[0] != 2") && result;
	result = test_equality_int(3, array_value_at(test, 1), "array_value_at(t, 1): t[1] != 3") && result;
	result = test_equality_int(5, array_value_at(test, 2), "array_value_at(t, 2): t[2] != 5") && result;
	result = test_equality_int(7, array_value_at(test, 3), "array_value_at(t, 3): t[3] != 7") && result;
	result = test_equality_int(11, array_value_at(test, 4), "array_value_at(t, 4): t[4] != 11") && result;
	result = test_equality_int(13, array_value_at(test, 5), "array_value_at(t, 5): t[5] != 13") && result;

	array_destroy(test);

	return result;
}

bool test_array_delete_last ()
{
	bool result = true;

	Array test = array_create(10);
	array_append(test, 2);
	array_append(test, 3);
	array_append(test, 5);
	array_append(test, 7);
	array_append(test, 11);
	array_append(test, 13);
	// 2 3 5 7 11 13

	array_delete_last(test);
	// 2 3 5 7 11
	result = test_equality_int(5, array_size(test), "array_delete_last: size != 5") && result;

	array_delete_last(test);
	// 2 3 5 7
	result = test_equality_int(4, array_size(test), "array_delete_last: size != 4") && result;

	array_destroy(test);

	return result;
}

bool test_array_delete_at ()
{
	bool result = true;

	Array test = array_create(10);
	array_append(test, 2);
	array_append(test, 3);
	array_append(test, 5);
	array_append(test, 7);
	array_append(test, 11);
	array_append(test, 13);
	// 2 3 5 7 11 13

	array_delete_at(test, 2);
	// 2 3 7 11 13
	result = test_equality_int(5, array_size(test), "array_delete_at(t, 2): size != 5") && result;
	result = test_equality_int(2, array_value_at(test, 0), "array_delete_at(t, 2): t[0] != 2") && result;
	result = test_equality_int(3, array_value_at(test, 1), "array_delete_at(t, 2): t[1] != 3") && result;
	result = test_equality_int(7, array_value_at(test, 2), "array_delete_at(t, 2): t[2] != 7") && result;
	result = test_equality_int(11, array_value_at(test, 3), "array_delete_at(t, 2): t[3] != 11") && result;
	result = test_equality_int(13, array_value_at(test, 4), "array_delete_at(t, 2): t[4] != 13") && result;

	array_delete_at(test, 0);
	// 3 7 11 13
	result = test_equality_int(4, array_size(test), "array_delete_at(t, 0): size != 4") && result;
	result = test_equality_int(3, array_value_at(test, 0), "array_delete_at(t, 0): t[0] != 2") && result;
	result = test_equality_int(7, array_value_at(test, 1), "array_delete_at(t, 0): t[1] != 7") && result;
	result = test_equality_int(11, array_value_at(test, 2), "array_delete_at(t, 0): t[2] != 11") && result;
	result = test_equality_int(13, array_value_at(test, 3), "array_delete_at(t, 0): t[3] != 13") && result;

	array_delete_at(test, 3);
	// 3 5 11
	result = test_equality_int(3, array_size(test), "array_delete_at(t, 3): size != 3") && result;
	result = test_equality_int(3, array_value_at(test, 0), "array_delete_at(t, 3): t[0] != 3") && result;
	result = test_equality_int(7, array_value_at(test, 1), "array_delete_at(t, 3): t[1] != 7") && result;
	result = test_equality_int(11, array_value_at(test, 2), "array_delete_at(t, 3): t[2] != 11") && result;

	array_destroy(test);

	return result;
}

bool test_array_delete_all_occurences ()
{
	bool result = true;

	Array test = array_create(10);
	array_append(test, 1);
	array_append(test, 2);
	array_append(test, 1);
	array_append(test, 2);
	array_append(test, 1);
	array_append(test, 2);
	array_append(test, 1);
	array_append(test, 2);
	// 1 2 1 2 1 2 1 2

	array_delete_all_occurences(test, 2);
	result = test_equality_int(1, array_value_at(test, 0), "array_delete_all_occurences(t, 2): t[0] != 1") && result;
	result = test_equality_int(1, array_value_at(test, 1), "array_delete_all_occurences(t, 2): t[1] != 1") && result;
	result = test_equality_int(1, array_value_at(test, 2), "array_delete_all_occurences(t, 2): t[2] != 1") && result;
	result = test_equality_int(1, array_value_at(test, 3), "array_delete_all_occurences(t, 2): t[3] != 1") && result;

	array_destroy(test);

	return result;
}

bool test_array_delete_all ()
{
	bool result = true;

	Array test = array_create(5);
	array_append(test, 1);
	array_append(test, 2);
	array_append(test, 3);
	array_append(test, 4);
	// 1 2 3 4

	array_delete_all(test);
	//
	result = test_equality_int(0, array_size(test), "array_delete_all: size != 0") && result;

	array_destroy(test);

	return result;
}

bool test_array_shift ()
{
	bool result = true;

	Array test = array_create(10);
	array_append(test, 1);
	array_append(test, 2);
	array_append(test, 3);
	array_append(test, 4);
	array_append(test, 5);
	array_append(test, 6);
	array_append(test, 7);
	array_append(test, 8);
	// 1 2 3 4 5 6 7 8

	array_shift(test, 2, 5, 1);
	// 1 2 3 3 4 5 6 8
	result = test_equality_int(1, array_value_at(test, 0), "array_shift(t, 2, 5, 1): t[0] != 1") && result;
	result = test_equality_int(2, array_value_at(test, 1), "array_shift(t, 2, 5, 1): t[1] != 2") && result;
	result = test_equality_int(3, array_value_at(test, 2), "array_shift(t, 2, 5, 1): t[2] != 3") && result;
	result = test_equality_int(3, array_value_at(test, 3), "array_shift(t, 2, 5, 1): t[3] != 3") && result;
	result = test_equality_int(4, array_value_at(test, 4), "array_shift(t, 2, 5, 1): t[4] != 4") && result;
	result = test_equality_int(5, array_value_at(test, 5), "array_shift(t, 2, 5, 1): t[5] != 5") && result;
	result = test_equality_int(6, array_value_at(test, 6), "array_shift(t, 2, 5, 1): t[6] != 6") && result;
	result = test_equality_int(8, array_value_at(test, 7), "array_shift(t, 2, 5, 1): t[7] != 8") && result;

	// 1 2 3 3 4 5 6 8
	array_shift(test, 3, 4, -2);
	// 1 3 4 3 4 5 6 8
	result = test_equality_int(1, array_value_at(test, 0), "array_shift(t, 3, 4, -2: t[0] != 1") && result;
	result = test_equality_int(3, array_value_at(test, 1), "array_shift(t, 3, 4, -2: t[1] != 3") && result;
	result = test_equality_int(4, array_value_at(test, 2), "array_shift(t, 3, 4, -2: t[2] != 4") && result;
	result = test_equality_int(3, array_value_at(test, 3), "array_shift(t, 3, 4, -2: t[3] != 3") && result;
	result = test_equality_int(4, array_value_at(test, 4), "array_shift(t, 3, 4, -2: t[4] != 4") && result;
	result = test_equality_int(5, array_value_at(test, 5), "array_shift(t, 3, 4, -2: t[5] != 5") && result;
	result = test_equality_int(6, array_value_at(test, 6), "array_shift(t, 3, 4, -2: t[6] != 6") && result;
	result = test_equality_int(8, array_value_at(test, 7), "array_shift(t, 3, 4, -2: t[7] != 8") && result;

	// 1 3 4 3 4 5 6 8
	array_shift(test, 4, 6, 4);
	// 1 3 4 3 4 5 6 8 4 5 6
	result = test_equality_int(11, array_size(test), "array_shift(t, 4, 6, 4): size != 11") && result;
	result = test_equality_int(20, array_capacity(test), "array_shift(t, 4, 6, 4): capacity != 20") && result;
	result = test_equality_int(1, array_value_at(test, 0), "array_shift(t, 4, 6, 4): t[0] != 1") && result;
	result = test_equality_int(3, array_value_at(test, 1), "array_shift(t, 4, 6, 4): t[1] != 3") && result;
	result = test_equality_int(4, array_value_at(test, 2), "array_shift(t, 4, 6, 4): t[2] != 4") && result;
	result = test_equality_int(3, array_value_at(test, 3), "array_shift(t, 4, 6, 4): t[3] != 3") && result;
	result = test_equality_int(4, array_value_at(test, 4), "array_shift(t, 4, 6, 4): t[4] != 4") && result;
	result = test_equality_int(5, array_value_at(test, 5), "array_shift(t, 4, 6, 4): t[5] != 5") && result;
	result = test_equality_int(6, array_value_at(test, 6), "array_shift(t, 4, 6, 4): t[6] != 6") && result;
	result = test_equality_int(8, array_value_at(test, 7), "array_shift(t, 4, 6, 4): t[7] != 8") && result;
	result = test_equality_int(4, array_value_at(test, 8), "array_shift(t, 4, 6, 4): t[8] != 4") && result;
	result = test_equality_int(5, array_value_at(test, 9), "array_shift(t, 4, 6, 4): t[9] != 5") && result;
	result = test_equality_int(6, array_value_at(test, 10), "array_shift(t, 4, 6, 4): t[10] != 6") && result;

	// 1 3 4 3 4 5 6 8 4 5 6
	array_shift(test, 1, 3, -3);
	// 3 3 4 3 4 5 6 8 4 5 6
	result = test_equality_int(3, array_value_at(test, 0), "array_shift(t, 1, 3, -3): t[0] != 3") && result;
	result = test_equality_int(3, array_value_at(test, 1), "array_shift(t, 1, 3, -3): t[1] != 3") && result;
	result = test_equality_int(4, array_value_at(test, 2), "array_shift(t, 1, 3, -3): t[2] != 4") && result;
	result = test_equality_int(3, array_value_at(test, 3), "array_shift(t, 1, 3, -3): t[3] != 3") && result;
	result = test_equality_int(4, array_value_at(test, 4), "array_shift(t, 1, 3, -3): t[4] != 4") && result;
	result = test_equality_int(5, array_value_at(test, 5), "array_shift(t, 1, 3, -3): t[5] != 5") && result;
	result = test_equality_int(6, array_value_at(test, 6), "array_shift(t, 1, 3, -3): t[6] != 6") && result;
	result = test_equality_int(8, array_value_at(test, 7), "array_shift(t, 1, 3, -3): t[7] != 8") && result;
	result = test_equality_int(4, array_value_at(test, 8), "array_shift(t, 1, 3, -3): t[8] != 4") && result;
	result = test_equality_int(5, array_value_at(test, 9), "array_shift(t, 1, 3, -3): t[9] != 5") && result;
	result = test_equality_int(6, array_value_at(test, 10), "array_shift(t, 1, 3, -3): t[10] != 6") && result;

	array_destroy(test);

	return test;
}

bool test_array_merge ()
{
	bool result = true;

	Array test_1 = array_create(5);
	array_append(test_1, 0);
	array_append(test_1, 2);
	array_append(test_1, 4);
	array_append(test_1, 6);
	array_append(test_1, 8);
	// 0 2 4 6 8
	Array test_2 = array_create(5);
	array_append(test_2, 1);
	array_append(test_2, 3);
	array_append(test_2, 5);
	array_append(test_2, 7);
	array_append(test_2, 9);
	// 1 3 5 7 9
	Array test_3;

	test_3 = array_merge(test_1, test_2);
	// 0 1 2 3 4 5 6 7 8 9
	result = test_equality_int(10, array_size(test_3), "t3 = array_merge(t1, t2): size t1 != 10") && result;
	result = test_equality_int(10, array_capacity(test_3), "t3 = array_merge(t1, t2): capacity t3 != 10") && result;
	result = test_equality_int(0, array_value_at(test_3, 0), "t3 = array_merge(t1, t2): t3[0] != 0") && result;
	result = test_equality_int(1, array_value_at(test_3, 1), "t3 = array_merge(t1, t2): t3[1] != 1") && result;
	result = test_equality_int(2, array_value_at(test_3, 2), "t3 = array_merge(t1, t2): t3[2] != 2") && result;
	result = test_equality_int(3, array_value_at(test_3, 3), "t3 = array_merge(t1, t2): t3[3] != 3") && result;
	result = test_equality_int(4, array_value_at(test_3, 4), "t3 = array_merge(t1, t2): t3[4] != 4") && result;
	result = test_equality_int(5, array_value_at(test_3, 5), "t3 = array_merge(t1, t2): t3[5] != 5") && result;
	result = test_equality_int(6, array_value_at(test_3, 6), "t3 = array_merge(t1, t2): t3[6] != 6") && result;
	result = test_equality_int(7, array_value_at(test_3, 7), "t3 = array_merge(t1, t2): t3[7] != 7") && result;
	result = test_equality_int(8, array_value_at(test_3, 8), "t3 = array_merge(t1, t2): t3[8] != 8") && result;
	result = test_equality_int(9, array_value_at(test_3, 9), "t3 = array_merge(t1, t2): t3[9] != 9") && result;
	array_destroy(test_3);

	array_append(test_1, 10);
	array_append(test_1, 12);
	test_3 = array_merge(test_1, test_2);
	// 0 1 2 3 4 5 6 7 8 9 10 12
	result = test_equality_int(12, array_size(test_3), "t3 = array_merge(t1, t2): size t3 != 15") && result;
	result = test_equality_int(15, array_capacity(test_3), "t3 = array_merge(t1, t2): capacity t3 != 15") && result;
	result = test_equality_int(0, array_value_at(test_3, 0), "t3 = array_merge(t1, t2): t3[0] != 0") && result;
	result = test_equality_int(1, array_value_at(test_3, 1), "t3 = array_merge(t1, t2): t3[1] != 1") && result;
	result = test_equality_int(2, array_value_at(test_3, 2), "t3 = array_merge(t1, t2): t3[2] != 2") && result;
	result = test_equality_int(3, array_value_at(test_3, 3), "t3 = array_merge(t1, t2): t3[3] != 3") && result;
	result = test_equality_int(4, array_value_at(test_3, 4), "t3 = array_merge(t1, t2): t3[4] != 4") && result;
	result = test_equality_int(5, array_value_at(test_3, 5), "t3 = array_merge(t1, t2): t3[5] != 5") && result;
	result = test_equality_int(6, array_value_at(test_3, 6), "t3 = array_merge(t1, t2): t3[6] != 6") && result;
	result = test_equality_int(7, array_value_at(test_3, 7), "t3 = array_merge(t1, t2): t3[7] != 7") && result;
	result = test_equality_int(8, array_value_at(test_3, 8), "t3 = array_merge(t1, t2): t3[8] != 8") && result;
	result = test_equality_int(9, array_value_at(test_3, 9), "t3 = array_merge(t1, t2): t3[9] != 9") && result;
	result = test_equality_int(10, array_value_at(test_3, 10), "t3 = array_merge(t1, t2): t3[10] != 10") && result;
	result = test_equality_int(12, array_value_at(test_3, 11), "t3 = array_merge(t1, t2): t3[11] != 12") && result;
	array_destroy(test_3);

	array_append(test_2, 11);
	array_append(test_2, 13);
	array_append(test_2, 15);
	test_3 = array_merge(test_2, test_1);
	// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 15
	result = test_equality_int(15, array_size(test_3), "t3 = array_merge(t2, t1): size t3 != 15") && result;
	result = test_equality_int(20, array_capacity(test_3), "t3 = array_merge(t2, t1): capacity t3 != 20") && result;
	result = test_equality_int(0, array_value_at(test_3, 0), "t3 = array_merge(t2, t1): t3[0] != 0") && result;
	result = test_equality_int(1, array_value_at(test_3, 1), "t3 = array_merge(t2, t1): t3[1] != 1") && result;
	result = test_equality_int(2, array_value_at(test_3, 2), "t3 = array_merge(t2, t1): t3[2] != 2") && result;
	result = test_equality_int(3, array_value_at(test_3, 3), "t3 = array_merge(t2, t1): t3[3] != 3") && result;
	result = test_equality_int(4, array_value_at(test_3, 4), "t3 = array_merge(t2, t1): t3[4] != 4") && result;
	result = test_equality_int(5, array_value_at(test_3, 5), "t3 = array_merge(t2, t1): t3[5] != 5") && result;
	result = test_equality_int(6, array_value_at(test_3, 6), "t3 = array_merge(t2, t1): t3[6] != 6") && result;
	result = test_equality_int(7, array_value_at(test_3, 7), "t3 = array_merge(t2, t1): t3[7] != 7") && result;
	result = test_equality_int(8, array_value_at(test_3, 8), "t3 = array_merge(t2, t1): t3[8] != 8") && result;
	result = test_equality_int(9, array_value_at(test_3, 9), "t3 = array_merge(t2, t1): t3[9] != 9") && result;
	result = test_equality_int(10, array_value_at(test_3, 10), "t3 = array_merge(t2, t1): t3[10] != 10") && result;
	result = test_equality_int(11, array_value_at(test_3, 11), "t3 = array_merge(t2, t1): t3[11] != 11") && result;
	result = test_equality_int(12, array_value_at(test_3, 12), "t3 = array_merge(t2, t1): t3[12] != 12") && result;
	result = test_equality_int(13, array_value_at(test_3, 13), "t3 = array_merge(t2, t1): t3[13] != 13") && result;
	result = test_equality_int(15, array_value_at(test_3, 14), "t3 = array_merge(t2, t1): t3[14] != 15") && result;
	array_destroy(test_3);

	array_destroy(test_1);
	array_destroy(test_2);

	return result;
}

bool test_array_concat ()
{
	bool result = true;

	Array test_1 = array_create(5);
	array_append(test_1, 0);
	array_append(test_1, 2);
	array_append(test_1, 4);
	array_append(test_1, 6);
	array_append(test_1, 8);
	// 0 2 4 6 8
	Array test_2 = array_create(5);
	Array test_3;

	test_3 = array_concat(test_1, test_2);
	// 0 2 4 6 8
	result = test_equality_int(5, array_size(test_3), "t3 = array_merge(t2, t1): size t3 != 5") && result;
	result = test_equality_int(10, array_capacity(test_3), "t3 = array_merge(t2, t1): capacity t3 != 10") && result;
	result = test_equality_int(0, array_value_at(test_3, 0), "t3 = array_concat(t1, t2): t3[0] != 0") && result;
	result = test_equality_int(2, array_value_at(test_3, 1), "t3 = array_concat(t1, t2): t3[1] != 2") && result;
	result = test_equality_int(4, array_value_at(test_3, 2), "t3 = array_concat(t1, t2): t3[2] != 4") && result;
	result = test_equality_int(6, array_value_at(test_3, 3), "t3 = array_concat(t1, t2): t3[3] != 6") && result;
	result = test_equality_int(8, array_value_at(test_3, 4), "t3 = array_concat(t1, t2): t3[4] != 8") && result;
	array_destroy(test_3);

	test_3 = array_concat(test_2, test_1);
	// 0 2 4 6 8
	result = test_equality_int(5, array_size(test_3), "t3 = array_merge(t2, t1): size t3 != 5") && result;
	result = test_equality_int(10, array_capacity(test_3), "t3 = array_merge(t2, t1): capacity t3 != 10") && result;
	result = test_equality_int(0, array_value_at(test_3, 0), "t3 = array_concat(t1, t2): t3[0] != 0") && result;
	result = test_equality_int(2, array_value_at(test_3, 1), "t3 = array_concat(t1, t2): t3[1] != 2") && result;
	result = test_equality_int(4, array_value_at(test_3, 2), "t3 = array_concat(t1, t2): t3[2] != 4") && result;
	result = test_equality_int(6, array_value_at(test_3, 3), "t3 = array_concat(t1, t2): t3[3] != 6") && result;
	result = test_equality_int(8, array_value_at(test_3, 4), "t3 = array_concat(t1, t2): t3[4] != 8") && result;
	array_destroy(test_3);

	array_append(test_2, 1);
	array_append(test_2, 3);
	array_append(test_2, 5);
	array_append(test_2, 7);
	array_append(test_2, 9);
	// 1 3 5 7 9

	test_3 = array_concat(test_1, test_2);
	//  0 2 4 6 8 1 3 5 7 9
	result = test_equality_int(10, array_size(test_3), "t3 = array_merge(t2, t1): size t3 != 10") && result;
	result = test_equality_int(10, array_capacity(test_3), "t3 = array_merge(t2, t1): capacity t3 != 10") && result;
	result = test_equality_int(0, array_value_at(test_3, 0), "t3 = array_concat(t1, t2): t3[0] != 0") && result;
	result = test_equality_int(2, array_value_at(test_3, 1), "t3 = array_concat(t1, t2): t3[1] != 2") && result;
	result = test_equality_int(4, array_value_at(test_3, 2), "t3 = array_concat(t1, t2): t3[2] != 4") && result;
	result = test_equality_int(6, array_value_at(test_3, 3), "t3 = array_concat(t1, t2): t3[3] != 6") && result;
	result = test_equality_int(8, array_value_at(test_3, 4), "t3 = array_concat(t1, t2): t3[4] != 8") && result;
	result = test_equality_int(1, array_value_at(test_3, 5), "t3 = array_concat(t1, t2): t3[5] != 1") && result;
	result = test_equality_int(3, array_value_at(test_3, 6), "t3 = array_concat(t1, t2): t3[6] != 3") && result;
	result = test_equality_int(5, array_value_at(test_3, 7), "t3 = array_concat(t1, t2): t3[7] != 5") && result;
	result = test_equality_int(7, array_value_at(test_3, 8), "t3 = array_concat(t1, t2): t3[8] != 7") && result;
	result = test_equality_int(9, array_value_at(test_3, 9), "t3 = array_concat(t1, t2): t3[9] != 9") && result;
	array_destroy(test_3);

	array_destroy(test_1);
	array_destroy(test_2);

	return result;
}

bool test_array_sort ()
{
	bool result = true;

	Array test = array_create(10);

	array_append(test, 3);
	array_append(test, 1);
	array_append(test, 5);
	array_append(test, 0);
	array_append(test, 8);
	array_append(test, 2);
	array_append(test, 1);
	// 3 1 5 0 8 2 1

	array_sort(test);
	// 0 1 1 2 3 5 8
	result = test_equality_int(7, array_size(test), "array_sort: size != 7") && result;
	result = test_equality_int(10, array_capacity(test), "array_sort: capacity != 10") && result;
	result = test_equality_int(0, array_value_at(test, 0), "array_sort: t[0] != 0") && result;
	result = test_equality_int(1, array_value_at(test, 1), "array_sort: t[1] != 1") && result;
	result = test_equality_int(1, array_value_at(test, 2), "array_sort: t[2] != 1") && result;
	result = test_equality_int(2, array_value_at(test, 3), "array_sort: t[3] != 2") && result;
	result = test_equality_int(3, array_value_at(test, 4), "array_sort: t[4] != 3") && result;
	result = test_equality_int(5, array_value_at(test, 5), "array_sort: t[5] != 5") && result;
	result = test_equality_int(8, array_value_at(test, 6), "array_sort: t[6] != 8") && result;

	array_destroy(test);

	return result;
}

bool test_array_search ()
{
	bool result = true;

	Array test = array_create(10);

	array_append(test, 0);
	array_append(test, 1);
	array_append(test, 1);
	array_append(test, 2);
	array_append(test, 3);
	array_append(test, 5);
	array_append(test, 8);
	// 0 1 1 2 3 5 8

	result = test_equality_int(3, array_search(test, 2), "array_search(t, 2): t[3]") && result;
	result = test_equality_int(1, array_search(test, 1), "array_search(t, 1): t[1]") && result;
	result = test_equality_int(6, array_search(test, 8), "array_search(t, 8): t[6]") && result;
	result = test_equality_int(-1, array_search(test, 4), "array_search(t, 4): t[-1]") && result;

	array_destroy(test);

	return result;
}

bool test_array_dsearch ()
{
	bool result = true;

	Array test = array_create(10);

	array_append(test, 0);
	array_append(test, 1);
	array_append(test, 1);
	array_append(test, 2);
	array_append(test, 3);
	array_append(test, 5);
	array_append(test, 8);
	// 0 1 1 2 3 5 8

	result = test_equality_int(3, array_dsearch(test, 2), "array_search(t, 2): t[3]") && result;
	result = test_equality_int(1, array_dsearch(test, 1), "array_search(t, 1): t[1]") && result;
	result = test_equality_int(6, array_dsearch(test, 8), "array_search(t, 8): t[6]") && result;
	result = test_equality_int(-1, array_dsearch(test, 4), "array_search(t, 4): t[-1]") && result;

	array_destroy(test);

	return result;
}

bool test_array ()
{
	bool result = true;

	result = test_array_create() && result;
	result = test_array_copy() && result;
	result = test_array_size() && result;
	result = test_array_capacity() && result;
	result = test_array_is_empty() && result;
	result = test_array_append() && result;
	result = test_array_append_at() && result;
	result = test_array_replace_at() && result;
	result = test_array_value_at() && result;
	result = test_array_delete_last() && result;
	result = test_array_delete_at() && result;
	result = test_array_delete_all_occurences() && result;
	result = test_array_delete_all() && result;
	result = test_array_shift() && result;
	result = test_array_merge() && result;
	result = test_array_concat() && result;
	result = test_array_sort() && result;
	result = test_array_search() && result;
	result = test_array_dsearch() && result;

	/*
	int size = 100;
	int val_max = 150;
	int nb_test = 50;
	Array test = array_create(size);
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		array_append(test, rand() % val_max);
	}
	printf("Tableau initial:\n");
	array_print(test);
	array_sort(test);
	printf("Tableau trié:\n");
	array_print(test);
	int val, pos;
	printf("Tests de recherche:\n");
	for (int i = 0; i < nb_test; i++)
	{
		val = rand() % val_max;
		pos = array_dsearch(test, val);
		if (pos < 0)
		{
			printf("%d n'est pas dans le tableau\n", val);
		}
		else
		{
			printf("%d est dans le tableau, à la position: %d\n", val, pos);
		}
	}
	array_destroy(test);
	*/

	return result;
}
