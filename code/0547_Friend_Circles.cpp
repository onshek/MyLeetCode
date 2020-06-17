class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        // DFS
        // TODO: symmetric matrix --> triangular matrix
        int res = 0;
        for (int i=0; i<M.size(); i++) {
            for (int j=0; j<M.size(); j++) {
                if (M[i][j] == 1) {
                    res ++;
                    dfs(i, j, M);
                }
            }
        }
        return res;
    }
private:
    void dfs(int i, int j, vector<vector<int>>& M) {
        if (M[i][j] == 1) {
            M[i][j] = 2;
            for (int x=0; x<M.size(); x++) { 
                dfs(j, x, M); 
            }
        }
    }
};