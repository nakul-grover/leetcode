class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        vector<int>suffix(n);
        suffix[n-1]=1;
        for(int i=n-2;i>=0;i--){
         suffix[i] =suffix[i+1]*nums[i+1];
        }
        int product =1;
        for(int i=0;i<n;i++){
         int res =  product * suffix[i];
         ans[i] = res;
         product = product*nums[i];
        }
        return ans;
    }
};