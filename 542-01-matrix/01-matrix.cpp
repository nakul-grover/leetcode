class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    visited[i][j] = 1;
                }
            }
        }

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;

            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if (newX >= 0 && newX < n && newY >= 0 && newY < m && visited[newX][newY] == 0) {
                    ans[newX][newY] = ans[x][y] + 1;
                    visited[newX][newY] = 1;
                    q.push({newX, newY});
                }
            }
        }

        return ans;
    }
};
