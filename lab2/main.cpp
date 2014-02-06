//
//  main.cpp
//  lab2
//
//  Created by Dylan Brown on 2/5/14.
//  Copyright (c) 2014 Dylan Brown. All rights reserved.
//

#include <iostream>

#define N 1024

class BitMap {
    
public:
    BitMap();
    bool search(int n, unsigned int blocks[]);
    void freeBlocks(int n, unsigned int blocks[]);
    bool searchConsecutive(int n,
                           unsigned int startAddress,
                           unsigned int blockAddress);
    
private:
    unsigned char bitmap[N];
};

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
