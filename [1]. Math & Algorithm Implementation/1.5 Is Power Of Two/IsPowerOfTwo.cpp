//
//  IsPowerOfTwo.cpp
//  interview-algorithm-question-solution
//
//  Created by Sun Shijie on 2018/5/2.
//  Copyright © 2018年 Shijie. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if ( n == 1){
            return true;
        }
        
        if ( n >= 2 && n%2 == 0){
            return isPowerOfTwo(n/2);
        }
        
        return false;
    }
};



