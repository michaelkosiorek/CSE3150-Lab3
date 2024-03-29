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

        int linked_list_length=10;
        node *linked_list = build_new_linked_list(linked_list_length);

        for (int i=0; i < linked_list_length-1; i++) {
            CHECK_FALSE(node_in_linked_list_points_to_self(linked_list, linked_list_length, i));
        }
        CHECK(node_in_linked_list_points_to_self(linked_list, linked_list_length, linked_list_length-1));

        pointer_jumping_algorithm(linked_list);
        node *last_node = get_last_node(linked_list);

        node *current_node = linked_list;
        while (current_node != last_node) {
            CHECK_EQ(current_node->next, last_node);
            current_node = current_node->dont_modify_next;
        }

    }

    SUBCASE("pointer jumping algo, 100 nodes") {

        int linked_list_length=100;
        node *linked_list = build_new_linked_list(linked_list_length);

        for (int i=0; i < linked_list_length-1; i++) {
            CHECK_FALSE(node_in_linked_list_points_to_self(linked_list, linked_list_length, i));
        }
        CHECK(node_in_linked_list_points_to_self(linked_list, linked_list_length, linked_list_length-1));

        pointer_jumping_algorithm(linked_list);
        node *last_node = get_last_node(linked_list);

        node *current_node = linked_list;
        while (current_node != last_node) {
            CHECK_EQ(current_node->next, last_node);
            current_node = current_node->dont_modify_next;
        }

    }

    SUBCASE("pointer jumping algo, 1 nodes") {

        int linked_list_length=1;
        node *linked_list = build_new_linked_list(linked_list_length);

        for (int i=0; i < linked_list_length-1; i++) {
            CHECK_FALSE(node_in_linked_list_points_to_self(linked_list, linked_list_length, i));
        }
        CHECK(node_in_linked_list_points_to_self(linked_list, linked_list_length, linked_list_length-1));

        pointer_jumping_algorithm(linked_list);
        node *last_node = get_last_node(linked_list);

        node *current_node = linked_list;
        while (current_node != last_node) {
            CHECK_EQ(current_node->next, last_node);
            current_node = current_node->dont_modify_next;
        }

    }

    SUBCASE("pointer jumping algo, 0 nodes") {

        int linked_list_length=0;
        node *linked_list = build_new_linked_list(linked_list_length);

        pointer_jumping_algorithm(linked_list);

        CHECK_EQ(linked_list, nullptr);

    }

}