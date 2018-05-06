//
//  CountPrimes.cpp
//  interview-algorithm-question-solution
//
//  Created by Sun Shijie on 2018/5/6.
//  Copyright © 2018年 Shijie. All rights reserved.
//

#include <stdio.h>
#include <math.h>

bool isPrime(int n){
    
    if(n == 1){
        return false;
    }
    
    for(int i = 3; i <= sqrt(n); i += 2){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int countPrimes(int n) {
    //首先>2的偶数肯定不是质数,只需要判断奇数
    int cnt = 0;
    if(n > 2) cnt ++;//2是质数
    for(int i = 3; i < n; i +=2 ){
        if(isPrime(i))
            cnt ++;
    }
    return cnt;
}
