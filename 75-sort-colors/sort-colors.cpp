class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int curr= 0;
        int l = 0;
        int r = n-1;
        while(curr<=r){
            if(nums[curr] == 0){
                swap(nums[curr], nums[l]);
                l++;
                curr++;
            }
            else if(nums[curr] == 2){
                swap(nums[curr], nums[r]);
                r--;
            }
            else{
                curr++;
            }
        }

        return;
    }
};