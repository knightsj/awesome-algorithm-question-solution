


#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int minSubArrayLen(int s, vector<int>& nums) {

    //using moving window

    int l = 0;  //left end
    int r = -1; //right end
    int sum = 0;
    int res = nums.size() + 1;

    while (l < nums.size()){
        if ( r+1 < nums.size() && sum < s){
            r++;
            sum += nums[r];
        }else{
            sum -= nums[l];
            l++;
        }

        if(sum>=s){
            res = min(res,r-l+1);
        }
    }

    if (res == nums.size() + 1){
        return 0;
    }

    return res;

}