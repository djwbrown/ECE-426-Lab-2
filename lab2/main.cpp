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
private:
    unsigned char bitmap[N];
};

BitMap::BitMap(void) {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < N; i++) {
        bitmap[i] = rand();
    }
}

int main(int argc, const char * argv[])
{
    /* Create a BitMap object */
    BitMap();
    
    return 0;
}
