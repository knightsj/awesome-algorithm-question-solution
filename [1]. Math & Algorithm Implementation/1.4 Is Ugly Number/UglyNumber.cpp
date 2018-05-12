//
//  UglyNumber.cpp
//  interview-algorithm-question-solution
//
//  Created by Sun Shijie on 2018/5/1.
//  Copyright © 2018年 Shijie. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    bool isUgly(int num) {
        
        if(num == 0){
            
            return false;
            
        }else if(num == 1){
            
            return true;
            
        }else{
            
            while(num % 2 == 0){
                
                num /= 2;
                
            }
            
            while(num % 3 == 0){
                
                num /= 3;
                
            }
            
            while(num % 5 == 0){
                
                num /= 5;
            }
            
            if(num == 1){
                
                return true;
                
            }else{
                
                return false;
                
            }
        }
    }
};


bool isUgly_1(int num){
    if (num == 0){
        return false;
    }else if (num == 1){
        return true;
    }else{
        while (num % 2 == 0) {
            num /= 2;
        }
        
        while (num % 3 == 0) {
            num /= 3;
        }
        
        while (num % 5 == 0) {
            num /= 5;
        }
        
        if (num == 1) {
            return true;
        }else{
            return false;
        }
    }
}

