class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int j = 0;
        unordered_map<int, int> m;
        long long count = 0; 
        long long ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
            count += m[nums[i]] - 1;

            while (count >= k) {
                ans += nums.size() - i;
                count -= m[nums[j]] - 1;
                m[nums[j]]--;
                j++;
            }
        }
        return ans;
    }
};
