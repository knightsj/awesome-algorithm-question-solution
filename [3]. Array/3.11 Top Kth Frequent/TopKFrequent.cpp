
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