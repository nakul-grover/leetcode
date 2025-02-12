class Solution {
public:
    int getDigitsSum(int i){
       int sum = 0;
       while(i > 0){
           sum += i % 10;
           i = i / 10;
       }
       return sum;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> m;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int sum = getDigitsSum(nums[i]);
            m[sum].push_back(nums[i]);
        }

        int ans = -1;
        
        for (auto& i : m) {
            if (i.second.size() > 1) {
                sort(i.second.begin(), i.second.end());
                int size = i.second.size();
                ans = max(ans, i.second[size - 1] + i.second[size - 2]);
            }
        }
        return ans;
    }
};
