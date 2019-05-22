#include <stdio.h>

/**
 * Runtime: 0 ms, faster than 100.00% of C online submissions for String to Integer (atoi).
 * Memory Usage: 7 MB, less than 67.20% of C online submissions for String to Integer (atoi).
*/
int myAtoi(char* str) {
    bool sign = false;
    long result = 0;
    while(isspace(*str))str++;  //1
    
    if (*str=='-' || *str=='+'){
        sign= *str=='-'; //
        str++;
    }
    
    if(*str > '9' || *str < '0')return 0;
    
    while (*str >= '0' && *str <= '9'){
        if (result <= INT_MAX){
            result = result * 10 + (*str-'0');
            str++;
        }else{
            break;
        }
    }
    if (result > INT_MAX){
        return sign ? INT_MIN : INT_MAX;
    }
    return sign ? -result : result;
}