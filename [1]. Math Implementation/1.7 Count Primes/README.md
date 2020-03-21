# Count Primes （质数的个数）



## From

[LeetCode 204](https://leetcode.com/problems/count-primes/description/)





## Question

Count the number of prime numbers less than a non-negative number, **n**.

**Example:**

```
Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
```

## Solution  



### C++

```c++
class Solution {
public:
    int countPrimes(int n) {        
        int count = 0;
        
        if(n > 2){
            count ++;
        }
        
        for(int i = 3; i < n; i +=2 ){
            
            if(isPrime(i)){
                count ++;
            }
        }
        return count;
    }
    
    bool isPrime(int n){

        if(n == 1){
            return false;
        }

        //only odd number
        for(int i = 3; i <= sqrt(n); i += 2){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
    
};
```

### Java

```java
public int countPrimes(int n) {
    
     int count = 0;
    
    if(n > 2){
        count ++;
    }
    
    for(int i = 3; i < n; i +=2 ){
        
        if(isPrime(i)){
            count ++;
        }
    }
    return count;
}

boolean isPrime(int n){

    if(n == 1){
        return false;
    }

    //only odd number
    for(int i = 3; i <= Math.sqrt(n); i += 2){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

```

### Python

```
def isPrime(num):
    if num <= 0:
        return False
    for i in range(2,num):
        if num % i == 0:
            return False
    return True

def get_prime_count(n):
    count = 0
    if n > 2:
        count += 1
    for i in range(3,n):
        if isPrime(i):
            count += 1
    return count
```
