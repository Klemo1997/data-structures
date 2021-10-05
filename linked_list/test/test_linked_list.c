#define CHEAT_NO_MATH

#include "cheat.h"
#include "cheats.h"
#include "linked_list.h"

CHEAT_TEST(linked_list_creation_works,
        cheat_assert_int(2, linked_list_create_node(2)->data);
)