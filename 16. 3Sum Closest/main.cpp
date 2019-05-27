#include <vector>

/**
 * Runtime: 8 ms, faster than 96.26% of C++ online submissions for 3Sum Closest.
 * Memory Usage: 8.7 MB, less than 76.44% of C++ online submissions for 3Sum Closest.
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        
        int clost = nums[0] + nums[1] + nums[2];
        if (clost >= target)return clost;
        int max = nums[size-3] + nums[size-2] + nums[size - 1];
        if (max < target) return max;
        
        
        for (int idx = 0; idx < size - 2; idx++){
            int begin = idx+1;
            int end = size - 1;
            while (begin < end){
                int cur = nums[idx] + nums[begin] + nums[end];
                if (cur < target){
                    if (clost < cur || target- cur < clost - target)clost = cur;
                    begin++;
                }else if (cur > target){
                    if (cur < clost || target - clost > cur - target)clost = cur;
                    end--;
                }else{
                    return target;
                }
                
                
            }
        }
        return clost;
    }
};