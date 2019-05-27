#include <vector>

/**
 * Runtime: 96 ms, faster than 95.29% of C++ online submissions for 3Sum.
 * Memory Usage: 15 MB, less than 76.55% of C++ online submissions for 3Sum.
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        int size = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < size - 2; i++){
            int a = nums[i];
            int begin = i + 1;
            int end = size - 1;
            if (i > 0 && a == nums[i-1]) continue;
            while(begin<end){
                int b = nums[begin];
                int c = nums[end];
                int sum = a + b + c;
                if (sum == 0){
                    res.push_back(vector<int>({a,b,c}));
                    while (begin < end && b == nums[++begin]);
                    while (begin < end && c == nums[--end]);
                }
                else if (sum > 0){
                    end--;
                }else{
                    begin++;
                }
            }
        }
        return res;
    }
};