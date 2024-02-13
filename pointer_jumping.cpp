#include <iostream>

#include "pointer_jumping.h"
#include "linked_list.h"

void pointer_jumping_algorithm(node *start) {
    if (start == nullptr || start->next == start) return;
    
    node *current_node = start;

    // find last node
    node *last_node;
    while(current_node->next!=current_node) {
        current_node = current_node->next;
    }
    last_node = current_node;
    // std::cout << last_node << " <-- last node" << std::endl;

    current_node = start;
    node *next_node;
    while (current_node->next!=current_node) {
        next_node = current_node->next;

        current_node->next = last_node;
        current_node = next_node;

    }
}
