#include <iostream>


/**
 * Runtime: 8 ms, faster than 92.68% of C++ online submissions for Longest Common Prefix.
 * Memory Usage: 8.9 MB, less than 66.42% of C++ online submissions for Longest Common Prefix.
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())return "";
        int max_len = INT_MAX;
        int count = strs.size();
        for (int i = 0; i < count; i++){
            int length = strs[i].length();
            max_len = min(max_len, length);
            for(int j = 0; j < max_len; j++){
                if (strs[i][j] != strs[0][j]){
                    max_len = j;
                    break;
                }
            }
        }
        return strs[0].substr(0,max_len);
        
    }
};