#include <vector>

/**
 * Runtime: 32 ms, faster than 28.82% of C++ online submissions for Kth Largest Element in an Array.
 * Memory Usage: 11.5 MB, less than 5.07% of C++ online submissions for Kth Largest Element in an Array.
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        quick_sort(nums, 0, nums.size()-1,k-1);
        return nums[k-1];
    }
    
    void quick_sort(vector<int>& nums, int left, int right, int k){
        int i = single_sort(nums, left, right);
        if (i == k)return;
        if (k < i)quick_sort(nums,left, i, k);
        else quick_sort(nums, i+1,right, k);
    }
    
    int single_sort(vector<int>& nums, int left, int right){
        int i = left,j = right,cur = i;
        while (i < j){
            while (nums[cur] >= nums[j] && i < j)j--;
            while (nums[cur] <= nums[i] && i < j)i++;
            if (i < j){
                swap(nums[i],nums[j]);
            }
        }
        if (left < i){
            swap(nums[left],nums[i]);
            cur = i;
        }
        return cur;
    }
};