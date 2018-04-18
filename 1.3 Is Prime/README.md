# Is Prime



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

