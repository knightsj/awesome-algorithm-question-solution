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

### Java
```java
class Solution {
    
    public void reverseString(char[] s) {
        
        for(int i = 0;i < s.length/2; i ++){
            char change = s[i];
            s[i] = s[s.length-1-i];
            s[s.length-1-i] = change;
        }
    }
    
}
```
### Python

```
def reverse_string(str):
    if len(str) == 1:
        return str
    return reverse_string(str[1:]) + str[0]

def reverse_string_2(str):
    if len(str) <= 1:
        return str
    i,j = 0, len(str)-1
    res = list(str)
    while i < j:
        temp = res[j]
        res[j] = res[i]
        res[i] = temp
        i += 1
        j -= 1
    return ''.join(res)
```
