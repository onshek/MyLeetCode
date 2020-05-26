/*
class Solution {
public:
    int climbStairs(int n) {
        return climb_stairs(0, n);
    }
     
    int climb_stairs(int i, int n) {
        if (i > n) return 0;
        if (i == n) return 1;
        return climb_stairs(i - 1, n) + climb_stairs(i -2, n);
    }
};
*/

class Solution {
public:
    int climbStairs(int n) {
        int first = 1;
        int second = 2;
        if (n == 1) return first;
        if (n == 2) return second;

        int result;
        for (int i = 3; i <= n; i++) {
            result = first + second;
            first = second;
            second = result;
        }
        return result;
    }
};