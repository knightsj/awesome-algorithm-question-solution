//
//  Single Number.cpp
//  interview-algorithm-question-solution
//
//  Created by Sun Shijie on 2018/4/26.
//  Copyright © 2018年 Shijie. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int length = nums.size();
        int result = 0 ;
        
        for (int i=0; i<length; i++)  {
            result ^= nums[i];
        }
        return result;
    }
};
