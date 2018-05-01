# Is Power Of Three



## Question

Given an integer, write a function to determine if it is a power of three.

**Follow up:**
Could you do it without using any loop / recursion?




## Solution  



### C++

```c++
class Solution {
public:
    bool isPowerOfThree(int n) {
        
        if(n>1){
            
            while(n%3==0){
               n=n/3;
            }
        }
        
        return n==1;
    }
};
```



```c++
class Solution {
public:
    bool isPowerOfThree(int n) {

      if(n>0){
            return 1162261467%n==0;
      }else{
          return false;
      }
	}
};
```

