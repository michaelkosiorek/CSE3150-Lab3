
#include "linked_list.h"


node * build_new_linked_list(int total_new_elements) {

    if (total_new_elements==0) return nullptr;

    node *head_node = new node;
    node *lag_node = head_node;

    node *next_node;
    for (int i=1; i < total_new_elements; i++) {
        next_node = new node;
        lag_node->next = next_node;
        lag_node->dont_modify_next = next_node;
        lag_node = next_node;
    }
    
    lag_node->next = lag_node;
    lag_node->dont_modify_next = lag_node;

    return head_node;
}


void print_linked_list_each_next_ptr(node * start) {

    if (start==nullptr) return;

    node *current_node=start;
    std::cout << current_node << " <-- Base node address"<< std::endl;
    while (current_node->next != current_node) {
        std::cout << current_node->next << std::endl;
        current_node = current_node->next;
    }
    std::cout << current_node->next << " <--Should match address above" << std::endl; // for last node

}

// returns false if node doesn't point to self
bool node_in_linked_list_points_to_self(node * start, int list_length, int node_number) {

    if (node_number>=list_length) return false;

    node *current_node = start;

    for (int i=0; i<node_number; i++) {
        current_node = current_node->next;
    }
    
    if (current_node->next==current_node) return true;
    else return false;

}

void print_linked_list_each_next_ptr_using_no_modify(node * start) {

    if (start==nullptr) return;

    node *current_node=start;
    std::cout << current_node << " <-- Base node address"<< std::endl;
    while (current_node->dont_modify_next != current_node) {
        std::cout << current_node->next << std::endl;
        current_node = current_node->dont_modify_next;
    }
    std::cout << current_node->next << std::endl; // for last node

}

node *get_last_node(node *start) {

    node *current_node = start;
    while (current_node->dont_modify_next!=current_node) {
        current_node = current_node->dont_modify_next;
    }
    return current_node;

}

bool all_nodes_point_to_last(node *start) {

    node *current_node = start;

    node *last_node = get_last_node(start);

    while (current_node->dont_modify_next != last_node) {
        if (current_node!=last_node) return false;
        else current_node = current_node->dont_modify_next;
    }
    return true; // no nodes that don't point to last found.

}