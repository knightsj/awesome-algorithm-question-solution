# Top Kth Frequent



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

