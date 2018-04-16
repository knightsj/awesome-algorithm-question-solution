//
//  majorityElement.cpp
//  interview-algorithm-question-solution
//
//  Created by Sun Shijie on 2018/4/16.
//  Copyright © 2018年 Shijie. All rights reserved.
//

#include <stdio.h>
#include <vector>

class Solution {
public:
    int majorityElement(std::vector<int> &num){
        
        int targetElem = 0;
        int count = 0;
        
        for(int i = 0; i < num.size(); i++){
            
            if(count == 0){
                
                targetElem = num[i];
                count = 1;
                
            }else{
                
                if(targetElem == num[i]){
                    count++;
                }else{
                    count--;
                }
            }
        }
        
        return targetElem;
    }
};

