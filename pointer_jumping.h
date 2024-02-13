#ifndef _POINTER_JUMPING_H_
#define _POINTER_JUMPING_H_

#include <iostream>
#include <cstdlib>


struct node { 
	struct node * next;
    struct node * dont_modify_next;
};

void pointer_jumping_algorithm(node *start);

#endif