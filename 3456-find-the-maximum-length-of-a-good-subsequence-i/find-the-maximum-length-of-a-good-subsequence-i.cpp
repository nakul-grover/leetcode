class Solution {
public:
    int n;
    int dp[501][502][26];
    int solve(vector<int>& nums, int k, int prev, int i){
        if(k < 0)
            return -1e9;
        if(i >= n)
            return 0;
            
        if(dp[i][prev+1][k] != -1)
            return dp[i][prev+1][k];
        
        int take = 0;
        if((prev ==-1 || nums[prev] == nums[i])){
            take= 1 + solve(nums, k, i, i+1);
        }
        else{
            take = 1 + solve(nums, k-1, i, i+1);
        }
        int not_take = solve(nums, k, prev, i+1);

        return dp[i][prev+1][k] = max(take, not_take);

    }

    int maximumLength(vector<int>& nums, int k) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));

        return solve(nums, k, -1, 0);
    }
};