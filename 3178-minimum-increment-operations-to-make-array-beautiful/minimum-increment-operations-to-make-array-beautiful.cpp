class Solution {
public:
    long long dp[100001][4];
    long long find(int i,int c,vector<int>&nums,int k){
        if(i == nums.size())return 0;
        
        if(dp[i][c] != -1)return dp[i][c];
        
        long long nochange = 1e18;
        if(c > 1){
            nochange = find(i+1,c-1,nums,k);
        }
        long long change = k - nums[i];
        change = max(0ll,change);
        
        change += find(i+1,3,nums,k);
        
        return dp[i][c] = min(nochange,change);
    }
    
    long long minIncrementOperations(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        
        return find(0,3,nums,k);
    }
};