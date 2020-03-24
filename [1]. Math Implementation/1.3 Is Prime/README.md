# Is Prime （是否是质数）



## From

Math problem



## Question

To prove if the given number is prime.



## Solution  



### C++

```c++
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
    int tmp =sqrt(num);
  
    for(int i= 2;i <=tmp; i++){
        if(num %i== 0){
            return false;
        }
    }
    return true ;
}

```


### Java

```java
public static  boolean is_prime_1 ( int num){

    int tmp =num - 1;

    for(int i= 2;i <=tmp; i++){

        if(num %i== 0){
            return false;
        }
    }
    return true ;
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
```

    
    
