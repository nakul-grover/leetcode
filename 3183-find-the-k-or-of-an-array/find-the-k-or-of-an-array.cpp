class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int ans =0;
        for(int i=0;i<32;i++){
            int key = 1<<i;
            int count=0;
            for(int j=0;j<nums.size();j++){
                if((key & nums[j]) == key){
                    cout<<(key & nums[j])<<" ";
                    count++;
                }
            }
            if(count>=k)
            ans =ans | key;
        }
        return ans;
    }
};