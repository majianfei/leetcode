#include <stdlib.h>

/**
 * Runtime: 4 ms, faster than 95.92% of C online submissions for Reverse Integer.
 * Memory Usage: 6.9 MB, less than 66.87% of C online submissions for Reverse Integer.
*/
int reverse(int x) {
    int a = x,b = 0;
    long ret = 0;
    do{
        if (a == 0)break;
        b = a % 10;
        a = a / 10;
        ret = ret * 10 + b;
    }while(true);
    
    return (ret > INT_MAX || ret < INT_MIN) ? 0 : ret;
}