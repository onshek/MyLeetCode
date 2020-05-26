class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) return false;
        int l = String.valueOf(x).length();
        int tmp = 0;
        if (l % 2 == 0) {
            l = (int) l / 2;
            tmp = x / (int) (Math.pow(10, l));
        }
        else {
            l = (int) (l - 1) / 2;
            tmp = x / (int) (Math.pow(10, l + 1));
        }
        int rev = 0;
        int pop = 0;
        for (; l > 0; l--) {
            pop = x % 10;
            rev = 10 * rev + pop;
            x /= 10;
        }
        if ((int) tmp == rev) return true;
        return false;
    }
}