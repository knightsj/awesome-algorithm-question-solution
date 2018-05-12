//
//  ContainsDuplicateI.cpp
//  interview-algorithm-question-solution
//
//  Created by Sun Shijie on 2018/4/12.
//  Copyright © 2018年 Shijie. All rights reserved.
//

#include <stdio.h>


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i ++){
            if(nums[i] == nums[i - 1])
                return true;
        }
        return false;
    }
};
