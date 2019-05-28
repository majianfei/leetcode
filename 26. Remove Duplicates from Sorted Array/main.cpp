#include <vector>

/**
 * Runtime: 20 ms, faster than 98.01% of C++ online submissions for Remove Duplicates from Sorted Array.
 * Memory Usage: 10.2 MB, less than 54.40% of C++ online submissions for Remove Duplicates from Sorted Array.
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)return 0;
        
        int result = 1;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] != nums[result-1]){
                nums[result++] = nums[i];
            }
        }
        return result;
    }
};