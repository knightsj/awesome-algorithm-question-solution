

#include <iterator>
#include <unordered_map>
#include <queue>
#include <vector>


using namespace std;


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
