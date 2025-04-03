class Solution {
public:

    bool isValid(int i,int j,int m,int n){
        if(i>=0 && j>=0 && i<m && j<n){
            return true;
        }
        else {
            return false;
        }
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> visited(m, vector<vector<int>>(n, vector<int>(k+1, 0)));
        

        queue<vector<int>>q;

        if(grid[0][0] == 1){
            k--;
        }

        q.push({0, 0, 0, k});
        visited[0][0][k] = 1;

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        int ans = 0;

        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                vector<int> top = q.front();
                q.pop();

                int x = top[0];
                int y = top[1];
                int remainingK = top[3];

                if(x == m-1 && y == n-1){
                    return ans;
                }

                for(int i = 0; i < dx.size(); i++){
                    int newX = x + dx[i];
                    int newY = y + dy[i];

                    if(isValid(newX, newY, m, n) && !visited[newX][newY][remainingK]){

                        if(grid[newX][newY] == 1 && remainingK > 0){
                            if(!visited[newX][newY][remainingK - 1])  
                                q.push({newX,newY,ans + 1, remainingK - 1});
                            visited[newX][newY][remainingK - 1] = 1;
                        }
                        else if(grid[newX][newY] == 0){
                            q.push({newX,newY,ans + 1, remainingK});
                        visited[newX][newY][remainingK] = 1;

                        }

                    }
                }
            }

            ans++;
        }

        return -1;
    }
};
