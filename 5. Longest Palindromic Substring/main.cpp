#include <iostream>


//TODO,优化
/**
 * Runtime: 200 ms, faster than 24.74% of C++ online submissions for Longest Palindromic Substring.
 * Memory Usage: 186.7 MB, less than 8.03% of C++ online submissions for Longest Palindromic Substring.
 */
class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        if (size <= 1)return s;
        int max_num = 1,start=0,end=0;
        vector<vector<int>> dp(size,vector<int>(size,0));
        
        for (int i = size - 1; i >= 0; i--){
            dp[i][i] = 1;
            for (int j = i+1; j <size; j++){
                if (s[i] == s[j]){
                    if (j - i <= 1)dp[i][j] = 2;
                    else dp[i][j] = dp[i+1][j-1]==0?0:dp[i+1][j-1]+2;
                }
                else{
                    dp[i][j] = 0;
                }
                if (max_num < dp[i][j]){
                    start = i;
                    end = j;
                    max_num = dp[i][j];
                }
            }
        }
        return s.substr(start, end-start+1);
    }
};