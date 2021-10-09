#define CHEAT_NO_MATH

#include "cheat.h"
#include "cheats.h"
#include "linked_list.h"

CHEAT_TEST(linked_list_creation_works,
        cheat_assert_int(2, linked_list_create_node(2)->data);
)

CHEAT_DECLARE(
    struct Node* getPrependedListFromIntArray(const int array[], const int size) {
        struct Node* linked_list = NULL;

        for (int i = 0; i < size; i++) {
            linked_list_prepend(&linked_list, array[i]);
        }

        return linked_list;
    }
)

CHEAT_TEST(linked_list_prepend_works,
    int testArr[1] = {1};
    cheat_assert_int(getPrependedListFromIntArray(testArr, 1)->data, 1);
)

CHEAT_TEST(linked_list_multi_prepend_works,
   int test2Array[2] = {1, 2};
   cheat_assert_int(getPrependedListFromIntArray(test2Array, 2)->data, 2);
   cheat_assert_int(getPrependedListFromIntArray(test2Array, 2)->next->data, 1);
)