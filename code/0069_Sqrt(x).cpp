class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;

        int left = 0;
        int right = x / 2;
        int current;
        long long num;
        while (left <= right) {
            current = (right + left) / 2;
            num = (long long) current * current;
            if (num > x) {
                right = current - 1;
            } else if (num < x) {
                left = current + 1;
            } else {
                return int(current);
            }
        }
        return (int) right;
    }
};