//
//  BitMap.cpp
//  lab2
//
//  Created by Dylan Brown on 2/6/14.
//  Copyright (c) 2014 Dylan Brown. All rights reserved.
//

#include "BitMap.h"

/* Find byte postion in the bitmap */
int bytePosition(int address) {
    return address / 8;
}

/* Find bit postion in the bitmap */
int bitPosition(int address) {
    if (address >= 8) {
        return address % 8;
    } else {
        return address;
    }
}

BitMap::BitMap(void) {
    
    /* Purpose: Default constructor method for BitMap. Creates a randomly initialized BitMap.
     * Inputs:  void
     */
    
    /* Initialize the bitmap with random binary values */
    srand((unsigned int)time(NULL));
    for (int i = 0; i < N; i++) {
        bitmap[i] = rand()%256;
    }
    
    /* Reset the bitmap[0][0] address. Mark as used: 0 */
    bitmap[0] = bitmap[0] & ~0x01;
}

bool BitMap::search(int n, unsigned int blocks[]) {
    
    /* Purpose: Searches for the first n free blocks in the BitMap.
     * Inputs:  int n                   size of blocks array
                unsigned int blocks[]   array of block addresses
     * Outputs: bool                    returns true if enough space is found
     */
    
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

void BitMap::writeBlocks(int n, unsigned int blocks[]) {
    
    /* Purpose: Marks the addresses contained in blocks array as used.
     * Inputs:  int n                   size of blocks array
                unsigned int blocks[]   array of block addresses
     * Outputs: void
     */
    
    /* Loop through n blocks and reset their bits as used: 0 */
    for (int index = 0; index < n; index++) {
        int address = blocks[index];
        bitmap[bytePosition(address)] = bitmap[bytePosition(address)] & (~0x01 << bitPosition(address));
    }
}

void BitMap::deleteBlocks(int n, unsigned int blocks[]) {
    
    /* Purpose: Marks the addresses contained in blocks array as free.
     * Inputs:  int n                   size of blocks array
                unsigned int blocks[]   array of block addresses
     * Outputs: void
     */
    
    /* Loop through n blocks and set their bits as free: 1 */
    for (int index = 0; index < n; index++) {
        int address = blocks[index];
        bitmap[bytePosition(address)] = bitmap[bytePosition(address)] | (0x01 << bitPosition(address));
    }
}

bool BitMap::searchConsecutive(int n, unsigned int startAddress, unsigned int *blockAddress) {
    
    /* Purpose: Searches for n consecutive free blocks in the BitMap beginning at the startAddress.
     * Inputs:  int n                       number of consecutive free blocks to find.
                unsigned int startAddress   method begins its search here
                unsigned int *blockAddress  a pointer to an array of block addresses
     * Outputs: bool                        returns true if the search was successful
     */
    
    bool spaceFound = false;
    int address = startAddress;
    int consecutiveBlocks = 0;
    
    while (!spaceFound) {
        for(int k = 0; consecutiveBlocks <= n; consecutiveBlocks++) {
            bool blockIsFree = bitmap[bytePosition(address)] & (0x01 << bitPosition(address));
            if (blockIsFree) {
                blockAddress[k++] = address;
            } else {
                consecutiveBlocks = 0;
                k = 0;
            }
            address++;                    // Increment the address
            if (address >= N * 8) break;  // Break at end of bitmap
        }
        if (consecutiveBlocks > n) spaceFound = true;
    }
    return spaceFound;
}
