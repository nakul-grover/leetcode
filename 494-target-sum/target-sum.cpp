class Solution {
public:
    int solve(vector<int>& nums, int index, int target, int sum, vector<vector<int>>& dp) {
        if (index == nums.size()) {
            return (sum == target) ? 1 : 0;
        }

        if (dp[index][sum + 1000] != -1) {
            return dp[index][sum + 1000];
        }

        int add = solve(nums, index + 1, target, sum + nums[index], dp);
        int subtract = solve(nums, index + 1, target, sum - nums[index], dp);

        return dp[index][sum + 1000] = add + subtract;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(), vector<int>(2001, -1));

        return solve(nums, 0, target, 0, dp);
    }
};
