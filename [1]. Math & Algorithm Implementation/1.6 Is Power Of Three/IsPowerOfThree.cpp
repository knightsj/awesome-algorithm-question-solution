//
//  IsPowerOfThree.cpp
//  interview-algorithm-question-solution
//
//  Created by Sun Shijie on 2018/5/2.
//  Copyright © 2018年 Shijie. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    bool isPowerOfThree(int n) {
        
        if(n>1){
            
            while(n%3 == 0){
                n=n/3;
            }
        }
        
        return n == 1;
    }
    
    //    bool isPowerOfThree(int n) {
    //
    //        if(n>0){
    //            return 1162261467%n==0;
    //        }else{
    //            return false;
    //        }
    //    }
};
