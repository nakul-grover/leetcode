class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
     int count1 = 0;
     int count2 = 0;
     int num1,num2 =-1;
     for(int i=0;i<nums.size();i++){
        if(num1 == nums[i]){
            count1 ++;
        }
        else if(num2 == nums[i]){
            count2 ++;
        }
        else if(count1 == 0){
            count1++;
            num1 = nums[i];
        }
        else if(count2 == 0){
            count2++;
            num2 = nums[i];
        }
        else{
            count1 --;
            count2 --;   
        }
     }
        count1 = 0;
        count2 = 0;

        for (int num : nums) {
            if (num == num1) count1++;
            if (num == num2) count2++;
        }
        
        vector<int> result;
        int n = nums.size();
        if (count1 > n / 3) result.push_back(num1);
        if (count2 > n / 3) result.push_back(num2);
        
        return result;

    }
};