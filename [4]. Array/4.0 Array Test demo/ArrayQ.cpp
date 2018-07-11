
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <queue>

using namespace std;


//有序的：二分法（二分查找），对撞指针（）；

class ArrayQuestion{

    public:


    void reorderEvenOdd(vector<int>& nums, int n){

        if (n == 0 || n == 1|| nums.size() == 0 || nums.size() == 1){
            return;
        }

        int l = 0;
        int r = n - 1;

        while (l < r){

            while (l < r && isOdd(nums[l])){
                l++;
            }

            while (l < r && (!isOdd(nums[r]))){
                r--;
            }

            swap(nums[l],nums[r]);

        }


    }

    void reorderEvenOdd1(vector<int>& nums, int n){

        if (n == 0 || n == 1|| nums.size() == 0 || nums.size() == 1){
            return;
        }

        int l = 0;
        int r = n - 1;

        while (l < r){

            while (l < r && isOdd(nums[l])){
                l++;
            }

            while (l < r && (!isOdd(nums[r]))){
                r--;
            }

            swap(nums[l],nums[r]);

        }


    }
    bool isOdd(int val){
        if (val & 2 == 1){
            return true;
        } else{
            return false;
        }
    }



    //包括重复数字
    bool containsDuplicate(vector<int>& nums) {

        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {

            if (m.find(nums[i]) != m.end()) {
                return true;
            };
            m[nums[i]] ++ ;
        }
        return false;
    }
    bool containsDuplicate1(vector<int>& nums) {




    }


    //two sum I: 一个数组两个元素的值等于目标值
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



    int majorityElement(std::vector<int> &num){

        int targetElem = 0;
        int count = 0;

        for(int i = 0; i < num.size(); i++){

            if(count == 0){

                targetElem = num[i];
                count = 1;

            }else{

                if(targetElem == num[i]){
                    count++;
                }else{
                    count--;
                }
            }
        }

        return targetElem;
    }


    int missingNumber(vector<int>& nums) {

        int n = nums.size();
        int ret = (n + 1)*n/2;
        for (int i = 0; i < n; i++){
            ret -= nums[i];
        }
        return ret;
    }
  


    //two sum II: 已经有序的数组 l<r,因为不能相交
    vector<int> twoSumII(vector<int>& numbers, int target) {

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

        int res[] = {-1,-1};
        return vector<int>(res,res+2);

    }


    //最大的第k个值： partition找出index = k
    int findKthLargest3(vector<int>& nums, int k) {

        k--;//eg. the second large number's index is 1
        int l = 0;
        int r = nums.size() - 1;
        int index= 0;

        while ( l < r){

            index = __partition(nums,l,r);

            if ( k < index ){
                r = index - 1;
            }else if ( k > index ){
                l = index + 1;
            }else {
                return nums[index];
            }
        }

        return nums[l];
    }


    int __partition(vector<int> &nums,int low,int high) {
        int l=low + 1;
        int r=high;
        int pivot = nums[low];

        while(l<=r)
        {
            if(nums[l]<pivot&&nums[r]>pivot){

                swap(nums[l],nums[r]);
            }

            if(nums[l]>=pivot) {
                l++;
            }

            if(nums[r]<=pivot) {
                r--;
            }
        }

        swap(nums[low],nums[r]);

        return r;
    }


    //合并有序数组：i = m + n - 1;先比较每组后面的元素到nums1；然后检查nums2是否还有剩余
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m + n - 1;

        //compare the element in the end of two vectors, put the bigger one into nums1
        while (m > 0 && n > 0) {

            if (nums1[m - 1] > nums2[n - 1]) {

                nums1[i] = nums1[m - 1];
                m--;

            } else {

                nums1[i] = nums2[n - 1];
                n--;
            }

            i--;
        }

        //if nums2 left, then put into nums1
        while (n > 0) {
            nums1[i] = nums2[n - 1];
            n--;
            i--;
        }
    }
    void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m + n - 1;

        while (m > 0 && n > 0){

            if (nums1[m - 1] > nums2[n - 1]){
                nums1[i] = nums1[m - 1];
                m--;
            } else{
                nums1[i] = nums2[n - 1];
                n--;
            }
            i--;
        }

        while (n > 0){
            nums1[i] = nums2[n - 1];
            i--;
            m--;
        }

    }


    template<typename T>
    //二分查找:缩小l和r的范围，l<=r
    int binarySearch( T arr[], int n, T target){

        int l = 0;
        int r = n - 1;//[l...r]

        while(l <= r){

            int mid = (l+r)/2;
            int value = arr[mid];

            if (arr[mid] == target){
                return mid;
            } else if (arr[mid] < target){
                l = mid + 1;
            } else{
                r = mid - 1;
            }
        }
        return -1;
    }
    template<typename T>
    int binarySearch1( T arr[], int n, T target){


        int i = 0;
        int j = n - 1;

        while ( i <= j){
            int mid = (i+j)/2;
            if (arr[mid] == target){
                return mid;
            }else if (arr[mid] < target){
                l = mid + 1;
            } else{
                r = mid - 1;
            }
        }
        return -1;

    }

    //移动0到末尾：不等于0的时候交换，swap
    void moveZeroes(vector<int>&nums){

         int k = 0;
         //[0...k)非0元素，k的左侧是非0
         //遍历数组：当当前值不为0的时候与k值交换，k++;当当前值为0的时候，只i++

         for ( int i = 0; i < nums.size();i++){

             if(nums[i] != 0){
                 if ( i != k){
                     swap(nums[k],nums[i]);
                     k++;
                  } else{
                     k++;
                 }
             };
         }
    }


    //   priority_queue<Type, Container, Functional>
    //   Type为数据类型， Container为保存数据的容器，Functional为元素比较方式。
    //   iter->first,iter->second;top().first;
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int>freqMap;//<value,freq>

        //生成一个map
        for (int i = 0; i < nums.size(); ++i) {
            freqMap[nums[i]]++;
        }

        if (k > freqMap.size()){
            //越界
        }


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



    //移除等于某值的元素:不等于某值，赋值为j
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
    int removeElement1(vector<int>& nums, int val) {



    }

    //数组去重：i与i-1比较，i = 1 , j = 1开始
    int removeDuplicates(vector<int>& nums) {

        if(nums.size() <= 1){
            return nums.size();
        }

        int len = 1;

        for(int i = 1; i < nums.size(); ++i) {

            if(nums[i] != nums[i-1]){

                nums[len] = nums[i];
                len++;
            }
        }
        return len;
    };


    int removeDuplicates1(vector<int>& nums) {



    };


    //三色旗：mid<=high,注意break
    void sortColors(vector<int>& nums) {

        //0-----low------mid-------high-----end;
        int low=0;
        int mid=0;
        int high = nums.size()-1;

        while(mid<=high){

            switch(nums[mid]){

                case 0:
                    swap(nums[low], nums[mid]);
                    low++;
                    mid++;
                    break;

                case 1:
                    mid++;
                    break;

                case 2:
                    swap(nums[mid], nums[high]);
                    high--;
                    break;

            }
        }

    }

    void sortColors2(vector<int>& nums) {





    }


    //两个数组的交叉元素：把一个数组放在set里面，遍历set，查找
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        set<int> record(nums1.begin(),nums1.end());
        set<int> resultSet;

        for (int i = 0; i < nums2.size(); ++i) {
            if(record.find(nums2[i]) != record.end()){
                resultSet.insert(nums2[i]);
            }
        }
        return vector<int>(resultSet.begin(),resultSet.end());

    }
    vector<int> intersection1(vector<int>& nums1, vector<int>& nums2) {





    }


    //最大的第k个值:最大堆
    int findKthLargest(vector<int>& nums, int k) {

        make_heap(nums.begin(), nums.end());//heap sort

        for (int i=0; i<k-1; i++){
            pop_heap(nums.begin(), nums.end());//将front放在end前部，剩下的元素构成新的heap，堆排序
            nums.pop_back();//删除最后一个元素
        }
        return nums[0];
    }

    //最大的第k个值:排序
    int findKthLargest1(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
    }

    //最大的第k个值:优先队列
    int findKthLargest2(vector<int>& nums, int k) {

        priority_queue<int> q(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; ++i) {
            q.pop();
        }
        return q.top();
    }








    //滑动窗口 l = 0; r = -1;
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



};