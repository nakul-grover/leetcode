class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        vector<int>prefixMax(nums.size(),-1);
        vector<int>suffixMax(nums.size(),-1);
        int n = nums.size();
        
        long long  ans = 0;
        for(int i=1;i<nums.size();i++){
            prefixMax[i] = max(prefixMax[i-1], nums[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            suffixMax[i] = max(suffixMax[i+1], nums[i+1]);
        }

        for(int i=1;i<n-1;i++){
            ans = max(ans,(long long)(prefixMax[i]- nums[i]) * suffixMax[i]);
        }

        return ans;
    }
};