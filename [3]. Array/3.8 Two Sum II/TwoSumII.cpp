
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


vector<int> twoSumII(vector<int>& numbers, int target) {

//    assert(numbers.size()>=2);

    int l = 0;
    int r = numbers.size() - 1;

    while ( l < r){

        if (numbers[l] + numbers[r] == target){
            int res[] = {l+1,r+1};
            return vector<int>(res,res+2);

        }else if (numbers[l] + numbers[r] < target){
            l++;
        } else{
            r--;
        }
    }
    throw invalid_argument("The input has no solution");

}