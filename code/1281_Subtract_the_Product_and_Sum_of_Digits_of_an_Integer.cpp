class Solution {
public:
    int subtractProductAndSum(int n) {
        int addRes = 0, mulRes = 1, num;
        while (n > 0) {
            num = n % 10; n /= 10;
            addRes += num; mulRes *= num;
        }
        return mulRes - addRes;
    }
};