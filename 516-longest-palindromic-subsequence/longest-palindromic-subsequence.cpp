class Solution {
public:
    int solve(string s1, string s2, int i, int j, vector<vector<int>>&dp){
        if(i== 0 || j==0){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s1[i-1] == s2[j-1]){
            return dp[i][j] = 1 + solve(s1,s2,i-1,j-1, dp);
        }
        return dp[i][j] = max(solve(s1,s2,i-1,j, dp), solve(s1,s2,i,j-1, dp));
    }
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        vector<vector<int>>dp(s1.size()+1, vector<int>(s.size()+1, 0));
        reverse(s.begin(), s.end());
        string s2 = s;
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=s.size();j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[s.size()][s.size()];
    }
};