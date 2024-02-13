#include "pointer_jumping.h"
#include "linked_list.h"

int main() {

    int linked_list_length=10;
    node *linked_list_head = build_new_linked_list(linked_list_length);
    print_linked_list_each_next_ptr(linked_list_head);
    //print_linked_list_each_next_ptr_using_no_modify(linked_list_head);


    pointer_jumping_algorithm(linked_list_head);
    print_linked_list_each_next_ptr_using_no_modify(linked_list_head);


    return 0;
}