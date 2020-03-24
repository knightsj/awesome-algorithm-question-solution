# Is Ugly Number （是否是丑数）



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



### Java

```java
class Solution {
    
    public boolean isUgly(int num) {
        
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
}
```



### Python

```
def isUgly(num):
    if num < 1:
        return False
    if num == 1:
        return True
    res = num
    while res%2 == 0:
        res = res//2
    while res%3 == 0:
        res = res//3
    while res%5 == 0:
        res = res//5
    if res == 1:
        return True
    return False
```
