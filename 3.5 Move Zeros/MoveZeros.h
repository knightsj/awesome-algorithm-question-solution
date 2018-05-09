
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void moveZeroes(vector<int>& nums) {

    int k = 0;//[0...k)非0元素

    for ( int i = 0; i < nums.size();i++){

        if(nums[i] != 0){

            if ( i != k){
                swap(nums[k++],nums[i]);
            } else{
                k++;
            }
        };

    }
}