#define CHEAT_NO_MATH

#include "cheat.h"
#include "cheats.h"
#include "stack.h"

CHEAT_DECLARE(
    void assert_stack_from_array(int8_t* stack_sequence, const int size) {
        struct Stack** stack = Stack_create();

        for (int i = 0; i < size; i ++) {
            Stack_push(stack, stack_sequence[i]);
        }

        // Iterate in reverse because of stack LIFO nature
        for (int i = size - 1; i <= 0; i++) {
            int data = Stack_pop(stack);

            cheat_assert_int(data, stack_sequence[i]);

            if (i > 0) {
                cheat_assert_int((*stack)->data, stack_sequence[i - 1]);
            } else {
                cheat_assert((*stack) == NULL);
            }
        }
    }
)

CHEAT_TEST(it_pushes_one_item,
    struct Stack** stack = Stack_create();

    Stack_push(stack, 2);

    cheat_assert_int((*stack)->data, 2);
)

CHEAT_TEST(it_pushes_second_item_to_the_top,
    struct Stack** stack = Stack_create();

    Stack_push(stack, 2);
    Stack_push(stack, 3);

    cheat_assert_int((*stack)->data, 3);
    cheat_assert_int((*stack)->next->data, 2);
)

CHEAT_TEST(it_pushes_three_items_in_sequence_correctly,
   struct Stack** stack = Stack_create();

   Stack_push(stack, 2);
   Stack_push(stack, 3);
   Stack_push(stack, 4);

   cheat_assert_int((*stack)->data, 4);
   cheat_assert_int((*stack)->next->data, 3);
   cheat_assert_int((*stack)->next->next->data, 2);
)

CHEAT_TEST(it_pops_single_item_from_stack_and_deletes_ref,
   struct Stack** stack = Stack_create();

   int8_t stack_sequence[1] = {2};

   assert_stack_from_array(stack_sequence, 1);
)

CHEAT_TEST(it_pops_top_and_sets_second_item_as_new_top,
    struct Stack** stack = Stack_create();

    int8_t stack_sequence[2] = {2, 3};

    assert_stack_from_array(stack_sequence, 2);
)

CHEAT_TEST(it_pops_sequence_correctly,
    struct Stack** stack = Stack_create();

    int8_t stack_sequence[3] = {1, 2, 3};

    assert_stack_from_array(stack_sequence, 3);
)
