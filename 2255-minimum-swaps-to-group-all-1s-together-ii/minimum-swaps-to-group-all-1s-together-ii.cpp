class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n  = nums.size();
        for(int i=0;i<n;i++){
            nums.push_back(nums[i]);
        }
        n=nums.size();
        int ones = 0;
        int ans = INT_MAX;
        for(int i=0;i<n/2;i++){
         if(nums[i]){
            ones++;
         }
        }
        int count = 0;
        for(int i=0;i<ones;i++){
           if(!nums[i]){
              count++;
           }
        }
        ans=min(ans,count);
        int j = 0;
        for(int i = ones;i<n;i++){
            if(!nums[i]){
                count++;
            }
            if(!nums[j]){
                count--;
            }
            cout<<count<<endl;
            ans=min(ans,count);
            j++;
        }
        return ans;

    }
};