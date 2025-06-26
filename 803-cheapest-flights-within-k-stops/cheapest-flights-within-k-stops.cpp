class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>v(n);
        for(int i=0;i<flights.size();i++){
            v[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int>dist(n,INT_MAX);
        queue<pair<int,pair<int,int>>>q;
        dist[src]=0;
        q.push({0,{src,0}});
        while(!q.empty()){
            pair<int,pair<int,int>>front=q.front();
            q.pop();
            int stops=front.first;
            int node=front.second.first;
            int cost=front.second.second;
            if(stops>k){
                continue;
            }
            for(auto iter: v[node]){
                int adjnode=iter.first;
                int edn=iter.second;
                if(cost+edn<dist[adjnode] && stops<=k){
                    dist[adjnode]=cost+edn;
                    q.push({stops+1,{adjnode,cost+edn}});
                }
            }
        }
        if(dist[dst]==INT_MAX){
return -1;}
        return dist[dst];
       
        
        
        
    }
};