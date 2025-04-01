class Solution {
private:
    long long find(vector<vector<int>> &q, int i, int n, vector<long long> &dp){
        if(i >= n) return 0;
        if(i == n - 1) return q[i][0];
        if(dp[i] != -1) return dp[i];

        long long ans = 0;
        long long pick = 0, notpick = 0;
        pick = q[i][0] + find(q, i + q[i][1] + 1, n, dp);
        notpick = find(q, i + 1, n, dp);
        return dp[i] = max(pick, notpick);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();

        vector<long long> dp(n + 1, -1);
        return find(questions, 0, n, dp);
    }
};