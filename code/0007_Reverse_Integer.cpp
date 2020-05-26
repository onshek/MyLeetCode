// #include <limits.h>

class Solution {
public:
    int reverse(int x) {
        int result = 0;
        if ((x == 0) || (x > INT_MAX) || (x < INT_MIN)) return result;

        while (x != 0) {
            if ((result > INT_MAX / 10) || (result < INT_MIN / 10)) return 0;
            result = result * 10 + x % 10;
            x = x / 10;
        }
        return result;
    }
};