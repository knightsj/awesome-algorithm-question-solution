# Intersection of Two Arrays (两个数组的交点元素)





## From

[LeetCode 349](https://leetcode.com/problems/intersection-of-two-arrays/description/)



## Question

Given two arrays, write a function to compute their intersection.

**Example:**
Given *nums1* = `[1, 2, 2, 1]`, *nums2* = `[2, 2]`, return `[2]`.

**Note:**

- Each element in the result must be unique.
- The result can be in any order.



## Solution  

### C++

```c++
#include <vector>
#include <set>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        set<int> record(nums1.begin(),nums1.end());
        set<int> resultSet;

        for (int i = 0; i < nums2.size(); ++i) {
            
            if(record.find(nums2[i]) != record.end()){
                resultSet.insert(nums2[i]);
            }
        }
    
        return vector<int>(resultSet.begin(),resultSet.end());
}
```



### Java

```java
class Solution {

    public int[] intersection(int[] nums1, int[] nums2) {
        
        HashMap<Integer,Integer> hs = new HashMap<Integer,Integer>();
        
        for(int x:nums1){
            
            hs.put(x, null);
        }
        

        ArrayList<Integer> arr=new ArrayList<Integer>();
        
        for(int y:nums2){
            
            if( hs.containsKey(y) && hs.get(y) == null ){
      
                hs.put(y, y);
                arr.add(y);
            }
        }
        
        int[] ret=new int[arr.size()];
        
        for( int i = 0;i < arr.size(); i++ ){
            ret[i] = arr.get(i);
        }
        
       
        return ret;
        
    }
}
```


