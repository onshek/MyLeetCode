class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<char> s;
        for (int i=0; i<preorder.size()-1;) {
            while (i < preorder.size()-1) {
                if (preorder[i] == ',') {
                    if (preorder[i-1] == '#') {
                        if (s.size() == 0) return false;
                        else s.pop();
                    }  
                    else s.push(1);
                }
                i++;
            }

        }

        if ((s.size() == 0) && (preorder[preorder.size()-1] == '#')) return true;
        else return false;
    }
};