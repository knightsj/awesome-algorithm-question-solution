import java.util.*;


public class Main {

    public static void main(String[] args) {

        System.out.println("Hello World!");

    }


    public static boolean containsDuplicate(int[] nums) {


        if (nums == null || nums.length <= 1) {

            return false;
        }

        HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();

        for (int i = 0; i < nums.length; i++) {

            if (map.put(nums[i], i) != null) {
                return true;
            }
        }

        return false;
    }


    public static int majorityElement(int[] nums) {

        int targetElement = 0;
        int count = 0;

        for(int i = 0; i < nums.length; i++){

            if(count == 0){

                targetElement = nums[i];
                count = 1;

            }else{

                if(targetElement == nums[i]){

                    count++;

                }else{

                    count--;

                }
            }
        }

        return targetElement;

    }

    public static int singleNumber(int[] nums) {

        int length = nums.length;
        int result = 0 ;

        for (int i = 0; i < length; i++)  {

            result ^= nums[i];
        }
        return result;
    }



    public static int missingNumber(int[] nums) {

        int n = nums.length;

        int ret = (n + 1)*n/2;

        for (int i = 0; i < n; i++){

            ret -= nums[i];

        }

        return ret;
    }



    public void moveZeroes(int[] nums) {

        int index = 0;

        for(int i = 0; i < nums.length; i++ ){

            if( nums[i] != 0 ){
                nums[index++] =  nums[i];
            }
        }

        for( int i = index; i < nums.length; i++ ){
            nums[i]=0;
        }
    }


    public int removeElement(int[] nums, int val) {

        int j = 0;

        for(int i = 0; i<nums.length; i++){

            if(nums[i] != val){

                if ( j != i){
                    nums[j] = nums[i];
                }

                j++;
            }
        }
        return j;
    }


    public void sortColors(int[] nums) {

        int low=0; //0..low:0
        int mid=0;
        int high = nums.length-1; //high...end

        while(mid<=high){

            switch(nums[mid]){

                case 0:

                    int tmp1;
                    tmp1 = nums[low];
                    nums[low] = nums[mid];
                    nums[mid]= tmp1;

                    low++;
                    mid++;
                    break;

                case 1:
                    mid++;
                    break;

                case 2:

                    int tmp;
                    tmp = nums[mid];
                    nums[mid] = nums[high];
                    nums[high]= tmp;


                    high--;
                    break;
            }
        }
    }

    public int[] twoSumII(int[] numbers, int target) {

        int[] result = new int[2];

        int n = numbers.length;

        if (n < 2) {
            return result;
        }


        int small  = numbers[0];
        int big    = numbers[n-1];

        for (int i = 0, j = n-1; i < n && j > 0 && j > i; ) {

            if (small + big == target) {
                result[0] = i + 1;
                result[1] = j + 1;
                break;
            }

            if (small + big > target) {
                j--;
            }

            if (small + big < target) {
                i++;
            }

            small = numbers[i];
            big = numbers[j];
        }

        return result;
    }




    public int minSubArrayLen(int s, int[] nums) {

        int l = 0;  //left end
        int r = -1; //right end
        int sum = 0;
        int n = nums.length;
        int res = n + 1;

        while (l < n) {

            if (r + 1 < n && sum < s) {

                r++;
                sum += nums[r];

            } else {
                sum -= nums[l];
                l++;
            }

            if (sum >= s) {

                res = Math.min(res, r - l + 1);
            }
        }

        if (res == n + 1) {

            return 0;
        }

        return res;

    }


    public int[] intersection(int[] nums1, int[] nums2) {

        HashMap<Integer,Integer> hs = new HashMap<Integer,Integer>();

        for(int x:nums1){

            hs.put(x, null);
        }


        ArrayList<Integer> arr=new ArrayList<Integer>();

        for(int y:nums2){

            if( hs.containsKey(y) && hs.get(y) == null ){

                hs.put(y, y);
                arr.add(y);
            }
        }

        int[] ret=new int[arr.size()];

        for( int i = 0;i < arr.size(); i++ ){
            ret[i] = arr.get(i);
        }


        return ret;

    }


    public void merge(int[] nums1, int m, int[] nums2, int n) {

        int i = m + n - 1;


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


        while (n > 0) {
            nums1[i] = nums2[n - 1];
            n--;
            i--;
        }

    }

    public int[] twoSumI(int[] nums, int target) {

        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        int[] result = new int[2];

        for (int i = 0; i < nums.length; i++) {

            if (map.containsKey(target - nums[i])) {

                result[0] = map.get(target - nums[i]);
                result[1] = i;
                return result;

            }
            map.put(nums[i], i);

        }

        return result;
    }


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



    public int findKthLargest1(int[] nums, int k) {

        PriorityQueue<Integer> q = new PriorityQueue<Integer>(k+1);

        for(int n : nums){
            q.offer(n);
            if(q.size() > k) q.poll();
        }

        return q.poll();
    }







}
