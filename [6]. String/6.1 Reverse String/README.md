# Reverse String (反转字符串)



## From

[LeetCode 344](https://leetcode.com/problems/reverse-string/description/)





## Question

Write a function that takes a string as input and returns the string reversed.

**Example:**
Given s = "hello", return "olleh".



## Solution  



### C++

```c++
class Solution {
public:
    
    string reverseString(string s) {
        
        int left = 0;
        int right = s.size() - 1;
        
        while (left < right) {
            
            char temp = s[left];
            s[left++] = s[right];
            s[right--] = temp;
        }
        return s;
    }
};
```

