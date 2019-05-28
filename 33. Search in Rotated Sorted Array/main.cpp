#include <vector>

/**
 * Runtime: 4 ms, faster than 96.56% of C++ online submissions for Search in Rotated Sorted Array.
 * Memory Usage: 8.9 MB, less than 57.41% of C++ online submissions for Search in Rotated Sorted Array.
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int middle = left + (right - left)/2;
            if (target == nums[middle])return middle;
            if (nums[middle] > nums[right]){
                if (nums[left] <= target && target < nums[middle]){
                    right = middle  - 1;
                }else{
                    left = middle + 1;
                }
            }
            else{
                if (nums[middle] < target && target <= nums[right]){
                    left = middle + 1;
                }
                else {
                    right = middle - 1;
                }
            }
        }
        return -1;
    }
};