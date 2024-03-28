class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i,j=0;
        int n=nums.size();
        int ans=0;
        unordered_map<int,int>m;
        for(i=0;i<n;i++){
            m[nums[i]]++;
            // cout<<i<<" "<<j<<endl;
            if(m[nums[i]]>k){
            // cout<<i<<" "<<j<<endl;
                ans=max(ans,i-j);
                // cout<<ans<<endl;
                // cout<<
                while(m[nums[i]]>k && i>=j){
                    m[nums[j]]--;
                    j++;
                    // cout<<"j"<<j<<endl;
                }
            }
        }
        ans=max(ans,i-j);
        return ans;

        
    }
};