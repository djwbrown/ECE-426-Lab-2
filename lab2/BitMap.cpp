//
//  BitMap.cpp
//  lab2
//
//  Created by Dylan Brown on 2/6/14.
//  Copyright (c) 2014 Dylan Brown. All rights reserved.
//

#include "BitMap.h"

BitMap::BitMap(void) {
    
    /* Initialize the bitmap with random binary values */
    srand((unsigned int)time(NULL));
    for (int i = 0; i < N; i++) {
        bitmap[i] = rand()%256;
    }
    
    /* Reset the bitmap[0][0] address. Mark as used. */
    bitmap[0] = bitmap[0] & 0xFE;
}

bool BitMap::search(int n, unsigned int blocks[]) {
    
    unsigned char testBit;
    int address;
    int k = 0;
    
    /* Find the free blocks by testing each address in the bitmap */
    for (int i = 0; i < N; i++) {
        testBit = 0x01;
        for (int j = 0; j < 8; j++) {
            address = i * 8 + j;
            if (address > (N * 8)) return false;
            if ((bitmap[i] & testBit) > 0) {
                blocks[k++] = address;
                if (--n == 0) return true;
            }
            testBit = testBit << 1;
        }
    }
    return false;
}
