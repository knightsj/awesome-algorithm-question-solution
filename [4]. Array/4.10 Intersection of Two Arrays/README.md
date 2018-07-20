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
int[] intersection(int[] A, int[] B) {
	
    Set<Integer> set = new HashSet<>();
    Set<Integer> res = new HashSet<>();

    for (int i: A) {
        set.add(i);
    }

    for (int i: B) {
        if (!set.add(i)) {
            res.add(i);
        }
    }

    int[] ret = new int[res.size()];
    int i = 0;
    for (int num: res) {
        ret[i++] = num;
    }

    return ret;
}
```

