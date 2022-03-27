#define CATCH_CONFIG_MAIN
//#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "dynamic_array_list.h"
#include "sorted_list.h"
#include "priority_queue.h"

typedef SortedList<int, DynamicArrayList<int> > SortedListType;
typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

TEST_CASE("Test Priority Queue methods", "[priority queue]") {
    PriorityQueueType pq;
    REQUIRE(pq.isEmpty());
    for (int i = 1; i <= 13; i++) {
        pq.add(i);
    }
    REQUIRE(!pq.isEmpty());
    for (int i = 13; i > 0; i--) {
        REQUIRE(pq.peek() == i);
        pq.remove();
    }
    REQUIRE(pq.isEmpty());
}
