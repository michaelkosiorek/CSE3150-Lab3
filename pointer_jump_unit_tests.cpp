#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include "pointer_jumping.h"
#include "linked_list.h"


TEST_CASE("pointer jumping unit tests") {
    
    SUBCASE("simple linked list testing") {

        int linked_list_length=10;
        node *linked_list = build_new_linked_list(linked_list_length);
        CHECK(node_in_linked_list_points_to_self(linked_list, linked_list_length, 9)); // 9 is last node, points to self
        CHECK_FALSE(node_in_linked_list_points_to_self(linked_list, linked_list_length, 8)); // 8th node points to last node
        CHECK_FALSE(node_in_linked_list_points_to_self(linked_list, linked_list_length, 10)); // there is no tenth node

    };

    SUBCASE("pointer jumping algo") {

        

    }

}