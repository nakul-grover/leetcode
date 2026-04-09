class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());

        for(int i=0;i<n;i++){
            if(i != 0 && nums[i] == nums[i-1]){
                continue;
            }
            int j= i+1;
            int k = n-1;

            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    while(nums[k] == nums[k-1] && j<k){
                        k--;
                        continue;
                    }
                    while(nums[j] == nums[j+1] && j<k){
                        j++;
                        continue;
                    }
                }
                if(sum > 0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return ans;
    }
};