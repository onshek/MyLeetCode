class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // DFS 
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                vector<pair<int, int>> tmpRecord;
                bool flag = true;
                if (board[i][j] == 'O') {
                    dfs(i, j, flag, tmpRecord, board);
                    if (!flag) {
                        for (auto p: tmpRecord) {
                            board[p.first][p.second] = 'O';
                        }
                    }
                }
            }
        }
    }
private:
    void dfs(int i, int j, bool& flag, vector<pair<int, int>>& tmpRecord, vector<vector<char>>& board) {
        if (board[i][j] == 'X') return;
        int hgt = board.size(), wdt = board[0].size();
        tmpRecord.push_back(pair<int, int>(i, j));
        if (i==0 || i==hgt-1 || j==0 || j==wdt-1) {
            flag = false;
        }
        if (board[i][j]=='O') board[i][j] = 'X';
        if (0 <= i-1  && board[i-1][j] == 'O') dfs(i-1, j, flag, tmpRecord, board);
        if (i+1 < hgt && board[i+1][j] == 'O') dfs(i+1, j, flag, tmpRecord, board);
        if (0 <= j-1  && board[i][j-1] == 'O') dfs(i, j-1, flag, tmpRecord, board);
        if (j+1 < wdt && board[i][j+1] == 'O') dfs(i, j+1, flag, tmpRecord, board);
    }
};