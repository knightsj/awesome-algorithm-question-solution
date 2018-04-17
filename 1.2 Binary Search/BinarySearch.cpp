//
//  BinarySearch.cpp
//  interview-algorithm-question-solution
//
//  Created by Sun Shijie on 2018/4/17.
//  Copyright © 2018年 Shijie. All rights reserved.
//

#include <stdio.h>

int binary_search(int* a, int len, int goal) {
    
    int low = 0;
    int high = len - 1;
    
    while (low <= high) {
        
        int middle = (high - low) / 2 + low;
        
        if (a[middle] == goal) {
            
            return middle;
            
        }else if (a[middle] > goal) {
            
            high = middle - 1;
            
        }else {
            
            low = middle + 1;
        }
    }
    return -1;
}

