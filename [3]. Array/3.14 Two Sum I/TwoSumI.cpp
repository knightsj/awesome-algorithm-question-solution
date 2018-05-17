


#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <queue>

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