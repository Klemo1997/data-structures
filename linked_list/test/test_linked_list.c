#define CHEAT_NO_MATH

#include "cheat.h"
#include "cheats.h"
#include "linked_list.h"

CHEAT_TEST(linked_list_creation_works,
        cheat_assert_int(2, linked_list_create_node(2)->data);
)

CHEAT_DECLARE(
    int testArr[1] = {1};
    int testTwoArray[1] = {2};
    int test2Array[2] = {1, 2};
    int testEmptyArray[0] = {};
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
    cheat_assert_int(getPrependedListFromIntArray(testArr, 1)->data, 1);
)

CHEAT_TEST(linked_list_multi_prepend_works,
   cheat_assert_int(getPrependedListFromIntArray(test2Array, 2)->data, 2);
   cheat_assert_int(getPrependedListFromIntArray(test2Array, 2)->next->data, 1);
)

CHEAT_DECLARE(
        struct Node* getAppendedListFromIntArray(const int array[], const int size) {
            struct Node* linked_list = NULL;

            for (int i = 0; i < size; i++) {
                linked_list_append(&linked_list, array[i]);
            }

            return linked_list;
        }
)

CHEAT_TEST(linked_list_append_works,
   cheat_assert_int(getAppendedListFromIntArray(testArr, 1)->data, 1);
)

CHEAT_TEST(linked_list_multi_append_works,
   cheat_assert_int(getAppendedListFromIntArray(test2Array, 2)->data, 1);
   cheat_assert_int(getAppendedListFromIntArray(test2Array, 2)->next->data, 2);
)

CHEAT_DECLARE(
        struct Node* deleteArrayFromLinkedList(struct Node* linked_list, const int array[], const int size) {
            for (int i = 0; i < size; i++) {
                linked_list_delete(&linked_list, array[i]);
            }

            return linked_list;
        }
)

CHEAT_TEST(linked_list_delete_on_empty_linked_list_works,
    struct Node* empty_linked_list = NULL;
    cheat_assert_ptrdiff(
    (ptrdiff_t) deleteArrayFromLinkedList(empty_linked_list, testArr, 1),
    (ptrdiff_t) NULL
    );
)

CHEAT_TEST(linked_list_delete_single_node_works,
    struct Node* empty_linked_list = NULL;
    cheat_assert_ptrdiff(
       (ptrdiff_t) deleteArrayFromLinkedList(
               getAppendedListFromIntArray(testArr, 1),
               testArr,
               1
           ),
       (ptrdiff_t) NULL
    );
)

CHEAT_TEST(linked_list_delete_head_works,
    struct Node* linked_list = getAppendedListFromIntArray(test2Array, 2);
    linked_list_delete(&linked_list, 1);
    cheat_assert_int(
       linked_list->data,
       2
    );
)

CHEAT_TEST(linked_list_delete_tail_works,
    struct Node* linked_list = getAppendedListFromIntArray(test2Array, 2);
    linked_list_delete(&linked_list, 2);
    cheat_assert_int(
       linked_list->data,
       1
    );
)