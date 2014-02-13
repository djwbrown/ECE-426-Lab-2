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
    
    /* Create a doubly linked list with NUM_BLOCKS elements */
    for (unsigned int addr = start_address + 1; addr < NUM_BLOCKS; addr++) {
        
        /* Allocate memory for the next node */
        node *next_node_ptr = new node;
        this_node->next = next_node_ptr;
        
        /* Create a link back to this_node */
        this_node->next->previous = this_node;
        
        /* Move along the list */
        this_node = this_node->next;
        this_node->address = addr;
    }
    
    /* Keep track of 'end', a pointer to the end of the list */
    end = this_node;
}

bool FreeList::writeBlocks(unsigned int n, unsigned int blocks[]) {
    unsigned int blocksRemaining = n;
    node *this_node = front;
    
    while (blocksRemaining > 0) {
        
        /* Test to see if we've reached the end of the linked list */
        if (this_node == end) return false;
        
        for (int index = 0; index < n; index++) {
            blocks[index] = this_node->address;
            
            /* Handle re-linking and moving the head pointer 'front' */
            if (this_node != front) {
                this_node->previous->next = this_node->next;
            }
            else {
                front = this_node->next;
            }
            
            /* Handle removal of this node from the FreeList */
            this_node = this_node->next;
            delete this_node;
            blocksRemaining--;
        }
    }
    return true;
}
