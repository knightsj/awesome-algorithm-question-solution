

#include <vector>

using namespace std;


int removeElement(vector<int>& nums, int val) {

    int length = nums.size();
    int j = 0;


    for(int i = 0; i<length; i++){
        //if equal, i move but j stay

        if(nums[i] != val){
            nums[j] = nums[i];
            j++;
        }
    }
    return j;

}
