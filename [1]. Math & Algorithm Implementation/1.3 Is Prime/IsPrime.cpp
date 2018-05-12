//
//  IsPrime.cpp
//  interview-algorithm-question-solution
//
//  Created by Sun Shijie on 2018/4/18.
//  Copyright © 2018年 Shijie. All rights reserved.
//

#include <stdio.h>
#include <math.h>


bool isPrime_1(int num)
{
    int tmp =num - 1;
    
    for(int i= 2;i <=tmp; i++){
        if(num %i== 0){
            return false;
        }
    }
    return true ;
}


bool isPrime_2(int num)
{
    
    if (n < 2){
        return false;
    }
    
    if (n == 2){
        return true;
    }
    
    int tmp =sqrt(num);
    
    for(int i= 2;i <= tmp; i++){
        
        if(num %i== 0){
            return false;
        }
    }
    return true ;
}


