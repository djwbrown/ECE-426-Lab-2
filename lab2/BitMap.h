//
//  BitMap.h
//  lab2
//
//  Created by Dylan Brown on 2/6/14.
//  Copyright (c) 2014 Dylan Brown. All rights reserved.
//

#ifndef __lab2__BitMap__
#define __lab2__BitMap__

#include <iostream>

#endif /* defined(__lab2__BitMap__) */

#define N 1024

class BitMap {
public:
    BitMap();
    bool search(int n, unsigned int blocks[]);
    void writeBlocks(int n, unsigned int blocks[]);
    void deleteBlocks(int n, unsigned int blocks[]);
    bool searchConsecutive(int n,
                           unsigned int startAddress,
                           unsigned int *blockAddress);
private:
    unsigned char bitmap[N];
};