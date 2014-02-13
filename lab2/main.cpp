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

int main(int argc, const char * argv[])
{
    
    /* Create a BitMap object and blocks array */
    BitMap map = BitMap();
    const int numBlocks = 10;
    unsigned int blocks[numBlocks];
    
    /* Output the blocks array, or error if search failed */
    if (map.search(numBlocks, blocks)) {
        std::cout << "List of " << numBlocks << " available blocks: ";
        for (int i = 0; i < numBlocks; i++) {
            std::cout << blocks[i] << " ";
        }
        std::cout << "\n";
    } else {
        std::cout << "Insufficient disk space available!\n";
    }
    
    /* Test writeBlocks and deleteBlocks */
    map.writeBlocks(numBlocks, blocks);
    unsigned int testBlocks[numBlocks];
    if (map.search(numBlocks, testBlocks)) {
        std::cout << "List of " << numBlocks << " available blocks: ";
        for (int i = 0; i < numBlocks; i++) {
            std::cout << testBlocks[i] << " ";
        }
        std::cout << "\n";
    } else {
        std::cout << "Insufficient disk space available!\n";
    }
    map.deleteBlocks(numBlocks, blocks);
    if (map.search(numBlocks, testBlocks)) {
        std::cout << "List of " << numBlocks << " available blocks: ";
        for (int i = 0; i < numBlocks; i++) {
            std::cout << testBlocks[i] << " ";
        }
        std::cout << "\n";
    } else {
        std::cout << "Insufficient disk space available!\n";
    }
    
    /* Test consecutive search */
    unsigned int consecutiveBlocks[numBlocks];
    unsigned int *blockAddress = consecutiveBlocks;
    if (map.searchConsecutive(numBlocks, 1, blockAddress)) {
        std::cout << "List of " << numBlocks << " consecutive blocks: ";
        for (int i = 0; i < numBlocks; i++) {
            std::cout << consecutiveBlocks[i] << " ";
        }
        std::cout << "\n";
    } else {
        std::cout << "Insufficient disk space available!\n";
    }
    
    /* Test FreeList */
    FreeList freelist = FreeList();
    unsigned int listBlocks[numBlocks];
    if (freelist.writeBlocks(numBlocks, listBlocks)) {
        std::cout << "List of " << numBlocks << " list blocks: ";
        for (int i = 0; i < numBlocks; i++) {
            std::cout << listBlocks[i] << " ";
        }
        std::cout << "\n";
    } else {
        std::cout << "Insufficient disk space available!\n";
    }
    
    return 0;
}
