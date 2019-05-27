#include <iostream>

/**
 * Runtime: 4 ms, faster than 93.43% of C++ online submissions for Valid Parentheses.
 * Memory Usage: 8.7 MB, less than 52.62% of C++ online submissions for Valid Parentheses.
*/
class Solution {
public:
    bool isValid(string s) {
        int size = s.size();
        if (size == 0)return true;
        if (size % 2 != 0)return false;
        int i = 0;
        stack<char> p;
        while (i < size){
            if (s[i] == '(' || s[i] == '[' ||s[i] == '{')p.push(s[i]);
            else{
                if(p.empty()) return false;
                if (s[i] == ')' && p.top() != '('){
                    return false;
                }
                if (s[i] == ']' && p.top() != '['){
                    return false;
                }
                if (s[i] == '}' && p.top() != '{'){
                    return false;
                }
                p.pop();
            }
            i++;
        }
        return p.empty();
    }
};