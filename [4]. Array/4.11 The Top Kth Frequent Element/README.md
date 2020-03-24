# Top Kth Frequent (出现频率最高的第k个元素)



## From

[LeetCode 347](https://leetcode.com/problems/top-k-frequent-elements/description/)



## Question

Given a non-empty array of integers, return the **k** most frequent elements.

For example,
Given `[1,1,1,2,2,3]` and k = 2, return `[1,2]`.

**Note: **

- You may assume *k* is always valid, 1 ≤ *k* ≤ number of unique elements.
- Your algorithm's time complexity **must be** better than O(*n* log *n*), where *n* is the array's size.



## Solution  

### C++

```c++
#include <iterator>
#include <unordered_map>
#include <queue>
#include <vector>


using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {

    unordered_map<int, int>freqMap;//<value,freq>

    //生成一个map
    for (int i = 0; i < nums.size(); ++i) {
        freqMap[nums[i]]++;
    }

    if (k > freqMap.size()){
        return NULL;
    }

    //pair:freq,value
    //iter：map里面的每一个元素
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

    for (unordered_map<int,int>::iterator iter = freqMap.begin();iter != freqMap.end(); iter++) {
        
        if (pq.size() == k) {
            
            if (iter->second > pq.top().first) {
                
                pq.pop();
                pq.push(make_pair(iter->second, iter->first));
            }
            
        } else {
            
            pq.push(make_pair(iter->second, iter->first));
        }
    }

    vector<int>res;
    while (!pq.empty()){
        res.push_back(pq.top().second);
        pq.pop();
    }
    return res;

}
```

### Java

```java
class Solution {
    
    public List<Integer> topKFrequent(int[] nums, int k) {
        
        Map<Integer, Integer> freqMap = new HashMap<>();
        
        for (int num : nums) {
            
            freqMap.put(num, freqMap.getOrDefault(num, 0) + 1);
        }
        
        
        List<Map.Entry<Integer, Integer>> list = new ArrayList<>(freqMap.entrySet());
        
        Collections.sort(list, new Comparator<Map.Entry<Integer, Integer>>() {
            @Override
            public int compare(Map.Entry<Integer, Integer> o1, Map.Entry<Integer, Integer> o2) {
                return o2.getValue() - o1.getValue();
            }
        });
        
        
        int count = 0;
        
        List<Integer> res = new ArrayList<>();
        
        for (Map.Entry<Integer, Integer> entry : list) {
            
            res.add(entry.getKey());
            ++count;
            if (count >= k) {
                break;
            }
        }
        return res;
    }
}
```


### Python

```
def top_k_element(arr, k):
    if not len(arr):
        return
    dic = {}
    for num in arr:
        if num not in dic:
            dic[num] = 1
        else:
            dic[num] += 1
    res = sorted(dic.items(), key=lambda x:x[1], reverse=True)
    res1 = []
    for i in range(0, k):
        res1.append(res[i][0])
    return res1
```
