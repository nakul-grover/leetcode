class Solution {
public:
    int solve(int index, vector<int>& arr, int k ,int n, vector<int>& dp) {
        if(index >= n)        
            return 0;
        if(dp[index] != -1)    
            return dp[index];

        int ans = 0;
        int max_element = -1;
        for(int i = index; (i < n) && (i-index +1 <= k); i++) {
            max_element = max(max_element, arr[i]);
            ans = max(ans, max_element*(i- index +1) + solve(i + 1, arr, k, n, dp));
        }
        return dp[index] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(0, arr, k, n , dp);
    }
};