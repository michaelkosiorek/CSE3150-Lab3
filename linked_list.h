#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include "pointer_jumping.h"


node * build_new_linked_list(int total_new_elements);
void print_linked_list_each_next_ptr(node * start);
void print_linked_list_each_next_ptr_using_no_modify(node * start); // for testing
bool node_in_linked_list_points_to_self(node * start, int list_length, int node_number);
node *get_last_node(node *start);

bool all_nodes_point_to_last(node *start); // for testing

#endif