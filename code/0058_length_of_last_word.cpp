class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        bool start = true;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != ' ' && start == true) {
                start = false;
                len += 1;
            } else if (s[i] == ' ' && start == false) {
                return len;
            } else if (start == false){
                len += 1;
            }
        }
    return len; 
    }
};