#include <iostream>

#include "linked_list.h"


using namespace std;

/*
build_new_linked_list:
	returns a pointer to the first node in the linked list
    If 0 == total_new_elements, then return null
*/
struct node * build_new_linked_list(int total_new_elements) {
    if (0 == total_new_elements) {
        return NULL;
    } else {
        struct node * root = new node;
        root->data = -1;
        struct node * linked_list = root;

        for (int i = 0 ; i < total_new_elements; i++) {
            linked_list->next = new node;
            linked_list->data = i+1;
            linked_list = linked_list->next;
        }

        return root;
    }
}

//get_linked_list_data_item_value: returns -1 if not enough nodes

int get_linked_list_data_item_value(struct node * start, int node_number, int total_elements) {
    if (node_number > total_elements) {
        return -1;
    } else {
        struct node * linked_list = start;

        for (int i = 0; i < node_number -1; i++) {
            linked_list = linked_list->next;
        }

        return linked_list->data;
    }
}

void print_linked_list(struct node * start, int total_elements) {
    struct node * linked_list =  start;

    for (int i = 0; i < total_elements; i++) {
        cout << linked_list->data << endl;
        linked_list = linked_list->next;
    }
}

void print_linked_list_by_jumpers(struct node * start, int total_elements) {

    struct node *linked_list = start;

    for (int i=0; i < number_of_nodes; i++) {
        if (linked_list->jumper==linked_list) break; // pointing to self
        cout << linked_list->data << endl;
        linked_lits = linked_list->next;
    }

}

void double_jumpers(struct node * start, int number_of_nodes) {

    struct node *linked_list = start;

    for (int i=0; i < number_of_nodes; i++) {
        if (linked_list->jumper==linked_list) break; // pointing to self
        cout << linked_list->data << endl;
        linked_lits = linked_list->next;
    }

}