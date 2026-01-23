class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int high = nums.size()-1;
        int ans = INT_MAX;
        while(start<=high){
            int mid = start + (high-start)/2;
            if(nums[mid]>= nums[start]){
                ans = min(ans, nums[start]);
                start = mid + 1;
            }
            else {
                ans = min(ans, nums[mid]);
                high = mid-1;
            }
        }
        return ans;
    }
};