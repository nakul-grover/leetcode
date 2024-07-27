class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& costy) {
        vector<vector<int>>cost(26,vector<int>(26,INT_MAX));
        int n = original.size();
        for(int i=0;i<26;i++){
            cost[i][i]=0;
        }
        for(int i=0;i<n;i++){
            cost[original[i]-'a'][changed[i]-'a'] = min(cost[original[i]-'a'][changed[i]-'a'],costy[i]);
        }

        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(cost[i][k]!=INT_MAX  && cost[k][j]!=INT_MAX){
                        cost[i][j] = min(cost[i][j],cost[i][k]+cost[k][j]);
                    }
                }
            }
        }
        long long ans =0;
        int s = source.size();
        for(int i=0;i<s;i++){
            if(cost[source[i]-'a'][target[i]-'a'] == INT_MAX){
                return -1;
            }
            ans += cost[source[i]-'a'][target[i]-'a'];
        }
        return ans;

    }
};