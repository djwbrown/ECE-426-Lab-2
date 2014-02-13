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
    
    /* Initialize the FreeList */
    struct node this_node = {start_address, nullptr};
    for (unsigned int addr = start_address; addr < NUM_BLOCKS; ++addr) {
        struct node next_node = {addr, nullptr};
        this_node.next = &next_node;
    }
}