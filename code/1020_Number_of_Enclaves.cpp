class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        int res = 0;
        for (int i=0; i<A.size(); i++) {
            for (int j=0; j<A[0].size(); j++) {
                if (A[i][j] == 1) {
                    int tmpNum = 0;
                    if (dfs(i, j, tmpNum, A)) {
                        res += tmpNum;
                    } 
                }
            }
        }
        return res;
    }
private:
    bool dfs(int i, int j, int& tmpNum, vector<vector<int>>& A) {
        int hgt = A.size(), wdt = A[0].size();
        bool b1 = true, b2 = true, b3 = true, b4 = true;
        if (i==0 || i==hgt-1 || j==0 || j==wdt-1) return false;
        if (A[i][j] == 1) {
            A[i][j] = 2; 
            tmpNum ++;
        }
        if (0 <= i-1  && A[i-1][j] == 1) b1 = dfs(i-1, j, tmpNum, A);
        if (i+1 < hgt && A[i+1][j] == 1) b2 = dfs(i+1, j, tmpNum, A);
        if (0 <= j-1  && A[i][j-1] == 1) b3 = dfs(i, j-1, tmpNum, A);
        if (j+1 < wdt && A[i][j+1] == 1) b4 = dfs(i, j+1, tmpNum, A);
        return b1 && b2 && b3 && b4;
    }
};