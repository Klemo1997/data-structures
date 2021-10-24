#define CHEAT_NO_MATH

#include <stdbool.h>
#include <string.h>

#include "cheat.h"
#include "cheats.h"
#include "array_list/array_list.h"

CHEAT_DECLARE(
    void assert_string(const char* received, const char* expected) {
        cheat_assert_int(strcmp(received, expected), 0);
    }
)

CHEAT_TEST(it_appends_single_string,
    struct ArrayList* arrayList = array_list_create();
    array_list_insert(&arrayList, "test");

    assert_string(array_list_at(arrayList, 0), "test");

    array_list_destroy(&arrayList);
)

CHEAT_TEST(it_appends_two_strings,
    struct ArrayList* arrayList = array_list_create();
    array_list_insert(&arrayList, "test");
    array_list_insert(&arrayList, "test2");

    assert_string(array_list_at(arrayList, 0), "test");
    assert_string(array_list_at(arrayList, 1), "test2");

    array_list_destroy(&arrayList);
)

CHEAT_TEST(it_does_not_resize_array_with_two_strings_appended,
    struct ArrayList* arrayList = array_list_create();
    array_list_insert(&arrayList, "test");
    array_list_insert(&arrayList, "test2");

    cheat_assert_int(arrayList->length, 2);
    cheat_assert_int(arrayList->size, 2);

    array_list_destroy(&arrayList);
)

CHEAT_TEST(it_does_resize_array_with_three_strings_appended,
    struct ArrayList* arrayList = array_list_create();
    array_list_insert(&arrayList, "test");
    array_list_insert(&arrayList, "test2");
    array_list_insert(&arrayList, "test3");

    cheat_assert_int(arrayList->length, 3);
    cheat_assert_int(arrayList->size, 4);

    array_list_destroy(&arrayList);
)

