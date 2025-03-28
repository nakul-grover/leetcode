class Solution {
public:
    int m, n;

    bool isValid(int x, int y){
        return (x>=0 && x<m && y>=0 && y<n);
    }

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {

         m = grid.size();
         n = grid[0].size();

        int size = queries.size();

        vector<pair<int,int>>q;
        for(int i=0;i<queries.size();i++){
            q.push_back({queries[i],i});
        }
        sort(q.begin(),q.end());

        int index = 0;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({grid[0][0], {0,0}});

        vector<int>ans(size);

        vector<vector<bool>>visited(m,vector<bool>(n,false));

        vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int count = 0;

        visited[0][0] = true;

        while(index<size) {
            int curr = q[index].first;
            while(!pq.empty() && curr > pq.top().first){
                count++;
                pair<int,pair<int,int>>top = pq.top();
                pq.pop();
                for(int i=0;i<dir.size();i++){
                    int newX = top.second.first + dir[i][0];
                    int newY = top.second.second + dir[i][1];

                    if(isValid(newX,newY) && visited[newX][newY] == false){
                        pq.push({grid[newX][newY],{newX,newY}});
                        visited[newX][newY] = true;
                    }
                }
            }
            ans[q[index].second] = count;
            index++;
        }

        return ans;


    }
};