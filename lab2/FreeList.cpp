//
//  FreeList.cpp
//  lab2
//
//  Created by Dylan Brown on 2/13/14.
//  Copyright (c) 2014 Dylan Brown. All rights reserved.
//

#include "FreeList.h"

FreeList::FreeList(void) {
    const unsigned int start_address = 1;
    
    /* Initialize the FreeList head pointer 'front' */
    node *this_node = new node;
    front = this_node;
    this_node->address = start_address;
    
    /* Create a linked list with NUM_BLOCKS elements */
    for (unsigned int addr = start_address + 1; addr < NUM_BLOCKS; addr++) {
        node *next_node_ptr = new node;
        this_node->next = next_node_ptr;
        this_node = this_node->next;
        this_node->address = addr;
    }
    
    /* Keep track of 'end', a pointer to the end of the list */
    end = this_node;
}
