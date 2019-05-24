#include <iostream>

/**
 * Runtime: 16 ms, faster than 98.33% of C++ online submissions for Container With Most Water.
 * Memory Usage: 9.9 MB, less than 62.61% of C++ online submissions for Container With Most Water.
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int water = 0;
        int i = 0, j = height.size() - 1;
        while (i < j){
            int h = min(height[i],height[j]);
            water = max(water, (j-i)*h);
            while (height[i]<=h && i < j)i++;
            while (height[j]<=h && i < j)j--;
        }
        return water;
    }
};