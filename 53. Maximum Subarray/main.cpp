#include <vector>

/**
 * Runtime: 4 ms, faster than 99.79% of C++ online submissions for Maximum Subarray.
 * Memory Usage: 9.4 MB, less than 61.21% of C++ online submissions for Maximum Subarray.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = 0;
        int now_sum = 0;
        int min_num = INT_MIN;
        
        for (int i = 0; i < nums.size(); i++){
            if (now_sum + nums[i] < 0)now_sum = 0;
            else{
                now_sum = now_sum + nums[i];
                max_sum = max(max_sum, now_sum);
            }
            if (max_sum == 0)min_num = max(min_num, nums[i]);
        }
        max_sum = max_sum > 0 ? max_sum : min_num;
        return max_sum;
    }
};