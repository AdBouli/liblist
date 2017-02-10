#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "test_toolbox.h"
#include "slist.h"

bool test_slist_create ()
{
    bool result = true;

    SList test = slist_create();
    result = test_equality_bool(true, slist_is_empty(test), "slist_create") && result;

    slist_destroy(test);

    return result;
}

bool test_slist_prepend ()
{
    bool result = true;

    SList test = slist_create();

    test = slist_prepend(test, 1);
    result = test_equality_int(1, slist_data(test), "slist_prepend(l, 1) val != 1") && result;
    test = slist_prepend(test, 2);
    result = test_equality_int(2, slist_data(test), "slist_prepend(l, 2) val != 2") && result;
    test = slist_prepend(test, 3);
    result = test_equality_int(3, slist_data(test), "slist_prepend(l, 3) val != 3") && result;
    test = slist_prepend(test, 4);
    result = test_equality_int(4, slist_data(test), "slist_prepend(l, 4) val != 4") && result;

    slist_destroy(test);

    return result;
}

bool test_slist_delete_first ()
{
    bool result = true;

    SList test = slist_create();
    test = slist_prepend(test, 1);
    test = slist_prepend(test, 2);
    test = slist_prepend(test, 3);
    test = slist_prepend(test, 4);

    test = slist_delete_first(test);
    result = test_equality_int(3, slist_data(test), "slist_delete_first(l): val != 3") && result;
    test = slist_delete_first(test);
    result = test_equality_int(2, slist_data(test), "slist_delete_first(l): val != 2") && result;
    test = slist_delete_first(test);
    result = test_equality_int(1, slist_data(test), "slist_delete_first(l): val != 1") && result;
    test = slist_delete_first(test);
    result = test_equality_bool(true, slist_is_empty(test), "slist_delete_first(l): not empty") && result;

    slist_destroy(test);

    return result;
}

bool test_slist_delete_after()
{
    bool result = true;

    SList test = slist_create();
    test = slist_prepend(test, 1);
    test = slist_prepend(test, 2);
    test = slist_prepend(test, 3);
    test = slist_prepend(test, 4);

    test = slist_delete_after(test, test);
    result = test_equality_int(2, slist_data(slist_next(test)), "slist_delete_after") && result;
    test = slist_delete_after(test, test);
    result = test_equality_int(1, slist_data(slist_next(test)), "slist_delete_after") && result;
    test = slist_delete_after(test, test);
    result = test_equality_bool(true, slist_is_empty(slist_next(test)), "slist_delete_after") && result;

    slist_destroy(test);

    return result;
}

bool test_slist_next()
{
    bool result = true;

    SList test = slist_create();
    test = slist_prepend(test, 1);
    test = slist_prepend(test, 2);
    test = slist_prepend(test, 3);
    test = slist_prepend(test, 4);

    SList p = slist_next(test);
    result = test_equality_int(3, slist_data(p), "slist_next: data != 3") && result;
    p = slist_next(p);
    result = test_equality_int(2, slist_data(p), "slist_next: data != 2") && result;
    p = slist_next(p);
    result = test_equality_int(1, slist_data(p), "slist_next: data != 1") && result;
    p = slist_next(p);
    result = test_equality_int(true, slist_is_empty(p), "slist_next: not empty") && result;

    slist_destroy(test);

    return result;
}

bool test_slist_data()
{
    bool result = true;

    SList test = slist_create();
    test = slist_prepend(test, 1);
    test = slist_prepend(test, 2);
    test = slist_prepend(test, 3);
    test = slist_prepend(test, 4);

    SList p = slist_next(test);
    result = test_equality_int(3, slist_data(p), "slist_data: data != 3") && result;
    p = slist_next(p);
    result = test_equality_int(2, slist_data(p), "slist_data: data != 2") && result;
    p = slist_next(p);
    result = test_equality_int(1, slist_data(p), "slist_data: data != 1") && result;

    slist_destroy(test);

    return result;
}

bool test_slist()
{
    bool result = true;

    result = test_slist_create() && result;
    result = test_slist_prepend() && result;
    result = test_slist_delete_first() && result;
    result = test_slist_delete_after() && result;
    result = test_slist_next() && result;
    result = test_slist_data() && result;

    return result;
}
