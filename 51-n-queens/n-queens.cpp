class Solution {
public:
    bool isSafe(vector<vector<int>>& board, int n, int i, int j) {
        for (int row = 0; row < i; row++) {
            if (board[row][j] == 1) return false;
        }
        for (int row = i - 1, col = j - 1; row >= 0 && col >= 0; row--, col--) {
            if (board[row][col] == 1) return false;
        }
        for (int row = i - 1, col = j + 1; row >= 0 && col < n; row--, col++) {
            if (board[row][col] == 1) return false;
        }
        return true;
    }

    void parseBoard(vector<vector<int>> board, int n, vector<vector<string>>& ans) {
        vector<string> temp;
        for (int i = 0; i < n; i++) {
            string s = "";
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 0) s += ".";
                else s += "Q";
            }
            temp.push_back(s);
        }
        ans.push_back(temp);
    }

    void solve(vector<vector<int>> board, int n, int i, vector<vector<string>>& ans) {
        if (i == n) {
            parseBoard(board, n, ans);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (isSafe(board, n, i, j)) {
                board[i][j] = 1;
                solve(board, n, i + 1, ans);
                board[i][j] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<vector<string>> ans;
        solve(board, n, 0, ans);
        return ans;
    }
};
