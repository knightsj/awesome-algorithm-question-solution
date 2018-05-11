

#include <vector>

using namespace std;


int removeElement(vector<int>& nums, int val) {

    int j = 0;

    for(int i = 0; i<nums.size(); i++){

        if(nums[i] != val){

            if ( j != i){
                nums[j] = nums[i];
            }

            j++;
        }
    }
    return j;
}
