# Is Ugly Number



## From

[LeetCode 263](https://leetcode.com/problems/ugly-number/description/)





## Question

Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include `2, 3, 5`. For example, `6, 8` are ugly while `14` is not ugly since it includes another prime factor `7`.

**Note:**

1. `1` is typically treated as an ugly number.
2. Input is within the 32-bit signed integer range.





## Solution  



### C++

```c++
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
```

