//
//  ReverseString.cpp
//  interview-algorithm-question-solution
//
//  Created by Sun Shijie on 2018/4/26.
//  Copyright © 2018年 Shijie. All rights reserved.
//

#include <stdio.h>


class Solution {
public:
    
    string reverseString(string s) {
        
        int left = 0;
        int right = s.size() - 1;
        
        while (left < right) {
            
            char t = s[left];
            s[left++] = s[right];
            s[right--] = t;
        }
        return s;
    }
};
