class Solution {
public:

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,long long>> adj[n];
        for(auto &itr : roads) {
            adj[itr[0]].push_back({itr[1] , itr[2]});
            adj[itr[1]].push_back({itr[0] , itr[2]});
        }

        vector<long long> distance(n , 1e12);
        vector<int> dp(n ,0);
        dp[0] = 1;
        distance[0] = 0;
        int MOD = (int)1e9 + 7;

        priority_queue<pair<long long,int> , vector<pair<long long,int>> , greater<pair<long long,int>>> pq;
        pq.push({0 , 0});

        while(!pq.empty()) {
            auto pair = pq.top();
            pq.pop();

            int node = pair.second;
            long long time = pair.first;

            for(auto &itr : adj[node]) {
                int Adj_Node = itr.first;
                 long long Req_time = itr.second;

                 if(time + Req_time < distance[Adj_Node]) {
                     distance[Adj_Node] = time + Req_time;
                     dp[Adj_Node] = dp[node];
                     pq.push({time + Req_time , Adj_Node});
                 }
                 else if(time + Req_time == distance[Adj_Node]) {
                      dp[Adj_Node] =  (dp[Adj_Node] + dp[node] ) % MOD;
                 }
            }
        }
        return dp[n-1];
    }
};