//
//  FreeList.h
//  lab2
//
//  Created by Dylan Brown on 2/13/14.
//  Copyright (c) 2014 Dylan Brown. All rights reserved.
//

#ifndef __lab2__FreeList__
#define __lab2__FreeList__

#include <iostream>

#endif /* defined(__lab2__FreeList__) */

#define NUM_BLOCKS 256

class FreeList {
public:
    FreeList();
    bool writeBlocks(unsigned int n, unsigned int blocks[]);
    bool deleteBlocks(unsigned int n, unsigned int blocks[]);
private:
    struct node {
        unsigned int address;
        struct node *next;
    };
    struct node *front = nullptr;
    struct node *end = nullptr;
};