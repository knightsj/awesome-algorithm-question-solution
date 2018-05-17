//
//  MissingNumber.cpp
//  interview-algorithm-question-solution
//
//  Created by Sun Shijie on 2018/4/26.
//  Copyright © 2018年 Shijie. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int len = nums.size();
        long long sum = static_cast<long long>(len) * (len + 1) / 2;
        for(auto val: nums) {
            sum -= val;
        }
        return static_cast<int>(sum);
    }
};


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int result = 0;
        
        for(auto num:nums){
            result ^= num;
        }
        
        int n = nums.size();
        
        for(int i = 0; i < nums.size() + 1; i++){
            result ^= i;
        }
        
        return result;
    }
};

class Solution {
public:
	   
     int missingNumber(vector<int>& nums) {
	        int n = nums.size();
	        int ret = (n + 1)*n/2;
	        for (int i = 0; i < n; i++){
	            ret -= nums[i];
	        }
	        return ret;
	}
};




