class Solution {
public:
    int solve(vector<int>& nums, int goal) {
        int j = 0;
        int n = nums.size();
        int ans = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (sum <= goal) {
                ans += (i - j + 1);
            } else {
                while (j<=i && sum > goal) {
                    sum -= nums[j];
                    j++;
                }
                ans+=(i-j+1);
            }
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums, goal) - solve(nums, goal - 1);
    }
};