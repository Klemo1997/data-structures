#define CHEAT_NO_MATH

#include <limits.h>
#include <stdbool.h>
#include "cheat.h"
#include "cheats.h"
#include "queue.h"

CHEAT_TEST(it_enqueues_first_item,
    struct Queue* queue = Queue_create(2);

    Queue_enqueue(&queue, 1);

    cheat_assert_int(Queue_front(queue), 1);
    cheat_assert_int(Queue_rear(queue), 1);
)

CHEAT_TEST(it_enqueues_two_items,
   struct Queue* queue = Queue_create(2);

   Queue_enqueue(&queue, 1);
   Queue_enqueue(&queue, 2);

   cheat_assert_int(Queue_front(queue), 1);
   cheat_assert_int(Queue_rear(queue), 2);
)

CHEAT_TEST(it_changes_queue_rear_on_enqueues,
   struct Queue* queue = Queue_create(2);

   Queue_enqueue(&queue, 1);
   cheat_assert_int(Queue_rear(queue), 1);

   Queue_enqueue(&queue, 2);
   cheat_assert_int(Queue_rear(queue), 2);
)

CHEAT_TEST(it_overflows_when_capacity_is_reached,
    struct Queue* queue = Queue_create(2);

    Queue_enqueue(&queue, 1);
    Queue_enqueue(&queue, 2);
    Queue_enqueue(&queue, 3);

    cheat_assert_int(Queue_front(queue), 1);
    cheat_assert_int(Queue_rear(queue), 2);
)

CHEAT_TEST(it_is_empty_after_create,
    struct Queue* queue = Queue_create(1);

    cheat_assert(Queue_isEmpty(queue) == true);
)

CHEAT_TEST(it_is_not_empty_after_enqueue,
    struct Queue* queue = Queue_create(1);

    Queue_enqueue(&queue, 1);

    cheat_assert(Queue_isEmpty(queue) == false);
)

CHEAT_TEST(it_is_empty_when_all_items_are_dequeued,
    struct Queue* queue = Queue_create(2);

    Queue_enqueue(&queue, 1);
    Queue_enqueue(&queue, 2);
    Queue_dequeue(&queue);
    Queue_dequeue(&queue);

    cheat_assert(Queue_isEmpty(queue) == true);
)

CHEAT_TEST(it_dequeues_only_item,
    struct Queue* queue = Queue_create(2);

    Queue_enqueue(&queue, 1);

    cheat_assert_int(Queue_dequeue(&queue), 1);
)

CHEAT_TEST(it_dequeues_two_items,
    struct Queue* queue = Queue_create(2);

    Queue_enqueue(&queue, 1);
    Queue_enqueue(&queue, 2);

    cheat_assert_int(Queue_dequeue(&queue), 1);
    cheat_assert_int(Queue_dequeue(&queue), 2);
)

CHEAT_TEST(it_changes_queue_front_on_dequeues,
    struct Queue* queue = Queue_create(2);

    Queue_enqueue(&queue, 1);
    Queue_enqueue(&queue, 2);

    cheat_assert_int(Queue_front(queue), 1);
    Queue_dequeue(&queue);
    cheat_assert_int(Queue_front(queue), 2);
    Queue_dequeue(&queue);
    cheat_assert_int(Queue_front(queue), INT_MIN);
)