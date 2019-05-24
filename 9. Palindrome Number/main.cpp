#include <iostream>

/**
 * Runtime: 16 ms, faster than 93.72% of C++ online submissions for Palindrome Number.
 * Memory Usage: 8.3 MB, less than 66.07% of C++ online submissions for Palindrome Number.
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0)return false;
        if(x<10)return true;
        int num=x;
        long a = 0;
        while (x){
            a = a * 10 + x%10;
            x=x/10;
        }
        if (a>INT_MAX)return false;
        return a==num;
    }
};