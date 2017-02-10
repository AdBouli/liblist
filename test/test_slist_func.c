#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "test_toolbox.h"
#include "slist_func.h"

bool test_slist_delete_all_occurences ()
{
    bool result = true;

    SList test = slist_create();
    test = slist_prepend(test, 1);
    test = slist_prepend(test, 2);
    test = slist_prepend(test, 1);
    test = slist_prepend(test, 2);
    test = slist_prepend(test, 1);
    test = slist_prepend(test, 2);
    test = slist_prepend(test, 1);
    test = slist_prepend(test, 2);

    test = slist_delete_all_occurences(test, 2);
    result = test_equality_bool(true, slist_is_empty(slist_find(test, 2)), "slist_delete_all_occurences: existing data") && result;
    result = test_equality_int(4, slist_length(test), "slist_delete_all_occurences: wrong length") && result;


    slist_destroy(test);

    return result;
}

bool test_slist_length ()
{
    bool result = true;

    SList test = slist_create();

    result = test_equality_int(0, slist_length(test), "slsit_length != 0") && result;

    test = slist_prepend(test, 1);
    test = slist_prepend(test, 2);
    test = slist_prepend(test, 3);

    result = test_equality_int(3, slist_length(test), "slsit_length != 3") && result;

    test = slist_delete_first(test);

    result = test_equality_int(2, slist_length(test), "slsit_length != 2 (after a remove)") && result;

    slist_destroy(test);

    return result;
}

bool test_slist_copy ()
{
    bool result = true;

    SList test = slist_create();

    SList test_copy = slist_copy(test);
    result = test_equality_bool(slist_is_empty(test), slist_is_empty(test_copy), "slist_copy: both are not empty") && result;
    slist_destroy(test_copy);

    test = slist_prepend(test, 1);
    test = slist_prepend(test, 2);
    test = slist_prepend(test, 3);

    test_copy = slist_copy(test);
    result = test_equality_int(slist_length(test), slist_length(test_copy), "slist_copy: both are not same length") && result;
    result = test_equality_int(slist_data(test), slist_data(test_copy), "slist_data: both are not same data") && result;
    SList p = slist_next(test);
    SList p_copy = slist_next(test_copy);
    result = test_equality_int(slist_data(p), slist_data(p_copy), "slist_data: both are not same data") && result;
    slist_destroy(test_copy);

    test = slist_delete_after(test, test);
    test_copy = slist_copy(test);
    result = test_equality_int(slist_length(test), slist_length(test_copy), "slist_copy: both are not same length (after a remove)") && result;
    result = test_equality_int(slist_data(test), slist_data(test_copy), "slist_data: both are not same data (after a remove)") && result;
    p = slist_next(test);
    p_copy = slist_next(test_copy);
    result = test_equality_int(slist_data(p), slist_data(p_copy), "slist_data: both are not same data (after a remove)") && result;

    slist_destroy(test_copy);
    slist_destroy(test);

    return result;
}

bool test_slist_append ()
{
    bool result = true;

    SList test = slist_create();

    test = slist_append(test, 1);
    result = test_equality_int(1, slist_length(test), "slist_append: invalid length != 1") && result;
    result = test_equality_int(1, slist_data(test), "slist_append: data != 1") && result;

    test = slist_append(test, 2);
    result = test_equality_int(2, slist_length(test), "slist_append: invalid length != 2") && result;
    result = test_equality_int(2, slist_data(slist_next(test)), "slist_append: data != 2") && result;

    slist_destroy(test);

    return result;
}

bool test_slist_reverse ()
{
    bool result = true;

    SList test = slist_create();

    test = slist_reverse(test);
    result = test_equality_bool(true, slist_is_empty(test), "slist_reverse: not empty") && result;

    test = slist_prepend(test, 1);
    test = slist_prepend(test, 2);
    test = slist_prepend(test, 3);
    test = slist_prepend(test, 4);

    test = slist_reverse(test);
    SList p = test;
    result = test_equality_int(1, slist_data(p), "slist_reverse: data != 1") && result;
    p = slist_next(p);
    result = test_equality_int(2, slist_data(p), "slist_reverse: data != 2") && result;
    p = slist_next(p);
    result = test_equality_int(3, slist_data(p), "slist_reverse: data != 3") && result;
    p = slist_next(p);
    result = test_equality_int(4, slist_data(p), "slist_reverse: data != 4") && result;

    slist_destroy(test);

    return result;
}

bool test_slist_concat ()
{
    bool result = true;

    SList test_1 = slist_create();
    SList test_2 = slist_create();

    test_1 = slist_concat(test_1, test_2);
    result = test_equality_bool(true, slist_is_empty(test_1), "slist_concat: not empty") && result;

    

    return result;
}

bool test_slist_last ()
{
    bool result = true;

    SList test = slist_create();
    test = slist_prepend(test, 1);
    test = slist_prepend(test, 2);
    test = slist_prepend(test, 3);

    result = test_equality_int(1, slist_data(slist_last(test)), "slist_last: val != 1") && result;
    test = slist_delete_after(test, slist_next(test));
    result = test_equality_int(2, slist_data(slist_last(test)), "slist_last: val != 2 (after a remove)") && result;

    slist_destroy(test);

    return result;
}

bool test_slist_nth ()
{
    bool result = true;

    SList test = slist_create();
    test = slist_prepend(test, 1);
    test = slist_prepend(test, 2);
    test = slist_prepend(test, 3);
    test = slist_prepend(test, 4);
    test = slist_prepend(test, 5);

    result = test_equality_int(5, slist_data(slist_nth(test, 1)), "slist_nth(l, 1): val != 5") && result;
    result = test_equality_int(4, slist_data(slist_nth(test, 2)), "slist_nth(l, 2): val != 4") && result;
    result = test_equality_int(3, slist_data(slist_nth(test, 3)), "slist_nth(l, 3): val != 3") && result;
    result = test_equality_int(2, slist_data(slist_nth(test, 4)), "slist_nth(l, 4): val != 2") && result;
    result = test_equality_int(1, slist_data(slist_nth(test, 5)), "slist_nth(l, 5): val != 1") && result;

    test = slist_delete_after(test, slist_nth(test, 2));
    result = test_equality_int(5, slist_data(slist_nth(test, 1)), "slist_nth(l, 1): val != 5") && result;
    result = test_equality_int(4, slist_data(slist_nth(test, 2)), "slist_nth(l, 2): val != 4") && result;
    result = test_equality_int(2, slist_data(slist_nth(test, 3)), "slist_nth(l, 3): val != 2") && result;
    result = test_equality_int(1, slist_data(slist_nth(test, 4)), "slist_nth(l, 4): val != 1") && result;

    slist_destroy(test);
    
    return result;
}

bool test_slist_nth_data ()
{
    bool result = true;

    SList test = slist_create();
    test = slist_prepend(test, 1);
    test = slist_prepend(test, 2);
    test = slist_prepend(test, 3);
    test = slist_prepend(test, 4);
    test = slist_prepend(test, 5);

    result = test_equality_int(5, slist_nth_data(test, 1), "slist_nth(l, 1): val != 5") && result;
    result = test_equality_int(4, slist_nth_data(test, 2), "slist_nth(l, 2): val != 4") && result;
    result = test_equality_int(3, slist_nth_data(test, 3), "slist_nth(l, 3): val != 3") && result;
    result = test_equality_int(2, slist_nth_data(test, 4), "slist_nth(l, 4): val != 2") && result;
    result = test_equality_int(1, slist_nth_data(test, 5), "slist_nth(l, 5): val != 1") && result;

    test = slist_delete_after(test, slist_nth(test, 2));
    result = test_equality_int(5, slist_nth_data(test, 1), "slist_nth(l, 1): val != 5") && result;
    result = test_equality_int(4, slist_nth_data(test, 2), "slist_nth(l, 2): val != 4") && result;
    result = test_equality_int(2, slist_nth_data(test, 3), "slist_nth(l, 3): val != 2") && result;
    result = test_equality_int(1, slist_nth_data(test, 4), "slist_nth(l, 4): val != 1") && result;

    slist_destroy(test);

    return result;
}

bool test_slist_find ()
{
    bool result = true;

    SList test = slist_create();
    test = slist_prepend(test, 1);
    test = slist_prepend(test, 2);
    test = slist_prepend(test, 3);
    test = slist_prepend(test, 4);
    test = slist_prepend(test, 5);
    test = slist_prepend(test, 6);
    test = slist_prepend(test, 7);
    test = slist_prepend(test, 8);
    test = slist_prepend(test, 9);

    result = test_equality_bool(false, slist_is_empty(slist_find(test, 2)), "slist_find(l, 2): data found") && result;
    result = test_equality_int(2, slist_data(slist_find(test, 2)), "slist_find(l, 2): data != 2") && result;
    result = test_equality_bool(false, slist_is_empty(slist_find(test, 4)), "slist_find(l, 2): data found") && result;
    result = test_equality_int(4, slist_data(slist_find(test, 4)), "slist_find(l, 2): data != 4") && result;
    result = test_equality_bool(false, slist_is_empty(slist_find(test, 7)), "slist_find(l, 2): data found") && result;
    result = test_equality_int(7, slist_data(slist_find(test, 7)), "slist_find(l, 2): data != 7") && result;
    result = test_equality_bool(false, slist_is_empty(slist_find(test, 9)), "slist_find(l, 2): data found") && result;
    result = test_equality_int(9, slist_data(slist_find(test, 9)), "slist_find(l, 2): data != 9") && result;
    result = test_equality_bool(true, slist_is_empty(slist_find(test, 0)), "slist_find(l, 2): data found") && result;
    result = test_equality_bool(true, slist_is_empty(slist_find(test, 11)), "slist_find(l, 2): data found") && result;

    slist_destroy(test);

    return result;
}

bool test_slist_position ()
{
    bool result = true;

    SList test = slist_create();
    test = slist_prepend(test, 1);
    test = slist_prepend(test, 2);
    test = slist_prepend(test, 3);
    test = slist_prepend(test, 4);
    test = slist_prepend(test, 5);
    test = slist_prepend(test, 6);
    test = slist_prepend(test, 7);
    test = slist_prepend(test, 8);
    test = slist_prepend(test, 9);

    result = test_equality_int(1, slist_position(test, slist_nth(test, 1)), "slist_position: != 1") && result;
    result = test_equality_int(2, slist_position(test, slist_nth(test, 2)), "slist_position: != 2") && result;
    result = test_equality_int(3, slist_position(test, slist_nth(test, 3)), "slist_position: != 3") && result;
    result = test_equality_int(4, slist_position(test, slist_nth(test, 4)), "slist_position: != 4") && result;
    result = test_equality_int(5, slist_position(test, slist_nth(test, 5)), "slist_position: != 5") && result;
    result = test_equality_int(6, slist_position(test, slist_nth(test, 6)), "slist_position: != 6") && result;
    result = test_equality_int(7, slist_position(test, slist_nth(test, 7)), "slist_position: != 7") && result;
    result = test_equality_int(8, slist_position(test, slist_nth(test, 8)), "slist_position: != 8") && result;
    result = test_equality_int(9, slist_position(test, slist_nth(test, 9)), "slist_position: != 9") && result;
    result = test_equality_int(-1, slist_position(test, NULL), "slist_position: error") && result;

    slist_destroy(test);

    return result;
}

bool test_slist_index ()
{
    bool result = true;

    SList test = slist_create();
    test = slist_prepend(test, 1);
    test = slist_prepend(test, 2);
    test = slist_prepend(test, 3);
    test = slist_prepend(test, 4);
    test = slist_prepend(test, 5);
    test = slist_prepend(test, 6);
    test = slist_prepend(test, 7);
    test = slist_prepend(test, 8);
    test = slist_prepend(test, 9);

    result = test_equality_int(9, slist_index(test, 1), "slist_index: != 9") && result;
    result = test_equality_int(8, slist_index(test, 2), "slist_index: != 8") && result;
    result = test_equality_int(7, slist_index(test, 3), "slist_index: != 7") && result;
    result = test_equality_int(6, slist_index(test, 4), "slist_index: != 6") && result;
    result = test_equality_int(5, slist_index(test, 5), "slist_index: != 5") && result;
    result = test_equality_int(4, slist_index(test, 6), "slist_index: != 4") && result;
    result = test_equality_int(3, slist_index(test, 7), "slist_index: != 3") && result;
    result = test_equality_int(2, slist_index(test, 8), "slist_index: != 2") && result;
    result = test_equality_int(1, slist_index(test, 9), "slist_index: != 1") && result;
    result = test_equality_int(-1, slist_index(test, 10), "slist_index: error") && result;

    slist_destroy(test);

    return result;
}

bool test_slist_func ()
{
    bool result = true;

    result = test_slist_delete_all_occurences() && result;
    result = test_slist_length() && result;
    result = test_slist_copy() && result;
    result = test_slist_append() && result;
    result = test_slist_reverse() && result;
    result = test_slist_concat() && result;
    result = test_slist_last() && result;
    result = test_slist_nth() && result;
    result = test_slist_nth_data() && result;
    result = test_slist_find() && result;
    result = test_slist_position() && result;
    result = test_slist_index() && result;

    return result;
}
