class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int count = 0;
        long long int sum =0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        long long int prefixSum = 0; 
        for(int i=0;i<n-1;i++){
            prefixSum += nums[i];
            if(prefixSum >= sum-prefixSum){
                count++;
            }
        }
        return count;
    }
};