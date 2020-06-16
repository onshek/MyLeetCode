class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // DFS, related: 0695, 1254
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    res ++;
                    dfs(i, j, grid);
                }
            }
        }
        return res;
    }
private:
    void dfs(int i, int j, vector<vector<char>>& grid) {
        grid[i][j] = '0';
        int hgt = grid.size(), wdt = grid[0].size();
        if (i+1 < hgt && grid[i+1][j] == '1') dfs(i+1, j, grid);
        if (i-1 >= 0  && grid[i-1][j] == '1') dfs(i-1, j, grid);
        if (j+1 < wdt && grid[i][j+1] == '1') dfs(i, j+1, grid);
        if (j-1 >= 0  && grid[i][j-1] == '1') dfs(i, j-1, grid);
    }
};
