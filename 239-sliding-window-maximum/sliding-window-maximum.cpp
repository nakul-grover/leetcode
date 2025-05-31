class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>res;
        for(int i = 0;i<nums.size(); i++){
            int num = nums[i];
            while(!dq.empty()  && num > dq.back()){
                dq.pop_back();
            }
            dq.push_back(nums[i]);
            if(i>=k && nums[i-k] == dq.front()){
                dq.pop_front();
            }
            if(i >= k-1){
                res.push_back(dq.front());
            }
        }
        return res;

    }
};