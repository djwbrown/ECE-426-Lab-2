//
//  main.cpp
//  lab2
//
//  Created by Dylan Brown on 2/5/14.
//  Copyright (c) 2014 Dylan Brown. All rights reserved.
//

#include <iostream>
#include "BitMap.h"
#include "FreeList.h"

/* Below is a collection of test output functions.
 * The arguments 'BitMap& map' and 'FreeList& freelist' are
 * class instances passed into the functions by reference.
 */

void testSearch(BitMap& map, int numBlocks, unsigned int blocks[]) {
    if (map.search(numBlocks, blocks)) {
        for (int i = 0; i < numBlocks; i++) {
            std::cout << blocks[i] << " ";
        }
        std::cout << "\n";
    } else {
        std::cout << "Insufficient disk space available!\n";
    }
}

void testSearch(FreeList& freelist, int numBlocks, unsigned int listBlocks[]) {
    if (freelist.writeBlocks(numBlocks, listBlocks)) {
        for (int i = 0; i < numBlocks; i++) {
            std::cout << listBlocks[i] << " ";
        }
        std::cout << "\n";
    } else {
        std::cout << "Insufficient disk space available!\n";
    }
}

void testConsecutiveSearch(BitMap& map, int numBlocks, unsigned int blocks[]) {
    if (map.searchConsecutive(numBlocks, 1, blocks)) {
        for (int i = 0; i < numBlocks; i++) {
            std::cout << blocks[i] << " ";
        }
        std::cout << "\n";
    } else {
        std::cout << "Insufficient disk space available!\n";
    }
}

int main(int argc, const char * argv[])
{

// (1) TEST the BitMap class
    std::cout << "-- PART 1: BitMap --\n\n";
    
    /* Create a BitMap object and blocks array with numBlocks elements initialized to zero */
    BitMap map = BitMap();
    const int numBlocks = 10;
    unsigned int blocks[numBlocks] = {0};
    
    /* Search in the BitMap to fill the blocks array, or error if search failed */
    std::cout << "List of first " << numBlocks << " free blocks in BitMap: ";
    testSearch(map, numBlocks, blocks);
    
    /* Test writeBlocks and search again for numBlocks free blocks */
    map.writeBlocks(numBlocks, blocks);
    std::cout << "\nBlocks WRITTEN to BitMap.\n\n";
    unsigned int nextBlocks[numBlocks];
    std::cout << "List of next " << numBlocks << " free blocks in BitMap: ";
    testSearch(map, numBlocks, nextBlocks);
    
    /* Test deleteBlocks and search again for numBlocks free blocks */
    map.deleteBlocks(numBlocks, blocks);
    std::cout << "\nFirst group of blocks DELETED from BitMap.\n\n";
    std::cout << "List of next " << numBlocks << " free blocks in BitMap: ";
    testSearch(map, numBlocks, blocks);
    
    /* Test consecutive search */
    unsigned int consecutiveBlocks[numBlocks];
    std::cout << "\nList of " << numBlocks << " consecutive free blocks: ";
    testConsecutiveSearch(map, numBlocks, consecutiveBlocks);
    
// (2) TEST the FreeList class
    std::cout << "\n\n-- PART 2: FreeList --\n\n";
    
    /* Create an instance of FreeList and another array of numBlocks blocks */
    FreeList freelist = FreeList();
    unsigned int listBlocks[numBlocks];
    
    /* Test searching for the first numBlocks blocks in the FreeList */
    std::cout << "Writing to first " << numBlocks << " free blocks in FreeList: ";
    testSearch(freelist, numBlocks, listBlocks);
    
    /* Test the freeing of blocks to the FreeList */
    freelist.deleteBlocks(numBlocks, listBlocks);
    std::cout << "\nFirst " << numBlocks << " blocks DELETED and appended to FreeList.\n\n";
    
    /* Test searching for the next numBlocks available blocks */
    std::cout << "List of next " << numBlocks << " free blocks in FreeList: ";
    testSearch(freelist, numBlocks, listBlocks);
    std::cout << "\n";
    
    return 0;
}
