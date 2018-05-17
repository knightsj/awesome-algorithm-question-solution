# Two Sum I



## Question



Given an array of integers, return **indices** of the two numbers such that they add up to a specific target.

You may assume that each input would have **exactly** one solution, and you may not use the *same* element twice.

**Example:**

```
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
```



## Solution  

### C++

```c++
#include <vector>
#include <unordered_map>

vector<int> twoSum(vector<int>& nums, int target) {

    unordered_map<int,int> record;
    for(int i = 0 ; i < nums.size() ; i ++){

        int complement = target - nums[i];
        if(record.find(complement) != record.end()){
            int res[] = {i, record[complement]};
            return vector<int>(res, res + 2);
        }

        record[nums[i]] = i;
    }

}
```

