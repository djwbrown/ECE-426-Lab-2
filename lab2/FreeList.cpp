//
//  FreeList.cpp
//  lab2
//
//  Created by Dylan Brown on 2/13/14.
//  Copyright (c) 2014 Dylan Brown. All rights reserved.
//

#include "FreeList.h"

FreeList::FreeList(void) {
    
    /* Purpose: Default constructor for FreeList. Creates a doubly-linked list with NUM_BLOCKS nodes.
     * Inputs:  void
     */
    
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
    
    /* Purpose: Finds the first n available blocks in the FreeList, starting at front.
     * Inputs:  unsigned int n          size of blocks array
                unsigned int blocks[]   array of block addresses
     * Outputs: bool                    returns true if enough write was successful
     */
    
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
                this_node->next->previous = this_node->previous;
            }
            else {
                front = this_node->next;
                this_node->next->previous = nullptr;
            }
            
            /* Handle removal of this_node from the FreeList */
            node *delete_me = this_node;
            this_node = this_node->next;
            delete delete_me;
            blocksRemaining--;
        }
    }
    return true;
}

void FreeList::deleteBlocks(unsigned int n, unsigned int blocks[]) {
    
    /* Purpose: Takes the addresses contained in the blocks array appends them to the FreeList.
     * Inputs:  unsigned int n          size of blocks array
                unsigned int blocks[]   array of block addresses
     * Outputs: void
     */
    
    /* Start at the end of the freelist and loop n times */
    node *this_node = end;
    for (int index = 0; index < n; index++) {
        
        /* Create a new node and setup the links */
        node *next_node_ptr = new node;
        this_node->next = next_node_ptr;
        this_node->next->previous = this_node;
        
        /* Traverse to the new node; set address and end */
        this_node = this_node->next;
        this_node->address = blocks[index];
        blocks[index] = 0;
        end = this_node;
    }
}
