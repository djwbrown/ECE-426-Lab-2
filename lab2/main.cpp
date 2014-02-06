//
//  main.cpp
//  lab2
//
//  Created by Dylan Brown on 2/5/14.
//  Copyright (c) 2014 Dylan Brown. All rights reserved.
//

#include <iostream>
#include "BitMap.h"

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
    
    return 0;
}
