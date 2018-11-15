# Fibonacci （斐波那契数列实现）



## From

《剑指offer》Question No.9



## Question

Code implementation of fibonacci.



## Solution  



### C++

```c++
long long Fibonacci(unsigned n)
{
    int result[2] = {0, 1};
    
    if(n < 2){
        return result[n];
    }
    
    long long  fibNMinusOne = 1;
    long long  fibNMinusTwo = 0;
    
    long long  fibN = 0;
    
    for(unsigned int i = 2; i <= n; ++ i){
        
        fibN = fibNMinusOne + fibNMinusTwo;
        
        fibNMinusTwo = fibNMinusOne;
        fibNMinusOne = fibN;
    }
    
    return fibN;
}
```

### Java

```java
// Iteration
long Fibonacci(long n) {

    if(n < 2){
        return n;
    }

    long  fibNMinusOne = 1;
    long  fibNMinusTwo = 0;

    long  fibN = 0;

    for(int i = 2; i <= n; ++i){

        fibN = fibNMinusOne + fibNMinusTwo;

        fibNMinusTwo = fibNMinusOne;
        fibNMinusOne = fibN;
    }
	
    return fibN;
}
```

```java
// Recursive
long Fibonacci(long n) { 
    if (n < 2) return n;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}
```