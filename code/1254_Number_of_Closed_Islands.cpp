class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        // DFS, related: 0695, 0200
        // for (auto x: grid) {
        //     for (auto y: x) {
        //         cout << y << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "++++++++++++++++++++" << endl;
        int res = 0;
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    if (dfs(i, j, grid)) {
                        res ++;
                    }
                }
            }
        }
        // for (auto x: grid) {
        //     for (auto y: x) {
        //         cout << y << " ";
        //     }
        //     cout << endl;
        // }
        return res;
    }
private:
    bool dfs(int i, int j, vector<vector<int>>& grid) {
        int hgt = grid.size(), wdt = grid[0].size();
        bool b1 = true, b2 = true, b3 = true, b4 = true;
        if (i==0 || i==hgt-1 || j==0 || j==wdt-1) {
            return false;
        }
        if (grid[i][j]==0) grid[i][j] = 2;
        if (i+1 < hgt && grid[i+1][j] == 0) b1 = dfs(i+1, j, grid);
        if (i-1 >= 0  && grid[i-1][j] == 0) b2 = dfs(i-1, j, grid);
        if (j+1 < wdt && grid[i][j+1] == 0) b3 = dfs(i, j+1, grid);
        if (j-1 >= 0  && grid[i][j-1] == 0) b4 = dfs(i, j-1, grid);
        return b1 && b2 && b3 && b4;
    }
};