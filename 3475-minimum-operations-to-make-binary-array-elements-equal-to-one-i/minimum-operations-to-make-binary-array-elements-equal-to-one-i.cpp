class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        if(nums[0] == 0){
            nums[0] = 1;
            nums[1] = nums[1] ^ 1;
            nums[2] = nums[2] ^ 1;
            count++;
        }
        for(int i=1;i<nums.size()-2;i++){
            if(nums[i] == 0){
                cout<<i<<endl;
               nums[i] = 1;
               nums[i+1] = nums[i+1] ^ 1;
               nums[i+2] = nums[i+2] ^ 1;
               count++;
            }
        }

        if(nums[nums.size()-1] != 0 && nums[nums.size()-2] != 0){
            return count;
        }

        return -1;


    }
};