class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // DFS
        int res = 0;
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                res = max(res, dfs(i, j, grid));
            }
        }
        return res;
    }

    int dfs(int i, int j, vector<vector<int>>& grid) {
        int tmpRes = 0;
        if (i==-1 || i==grid.size() || j==-1 || j==grid[0].size() || grid[i][j] == 0)
            return tmpRes;
        tmpRes ++;
        grid[i][j] = 0;
        tmpRes = tmpRes + dfs(i, j+1, grid) + dfs(i, j-1, grid) + dfs(i-1, j, grid) + dfs(i+1, j, grid);
        return tmpRes;
    }
};