class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        long long int ans=0;
        while(k){
            int x=pq.top();
            pq.pop();
            ans+=x;
            pq.push(ceil(x/3.0));
            k--;
        }
        return ans;
        
    }
};