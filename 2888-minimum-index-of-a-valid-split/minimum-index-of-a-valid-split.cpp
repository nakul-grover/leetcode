class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int x =-1;
        int count = 0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == x){
                count ++;
            }
            else{
                count--;
            }
            if(count <= 0){
                x = nums[i];
                count++;
            }
        }

        int totalFreq = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == x){
                totalFreq++;
            }
        }
        int  n = nums.size();
        
        cout<<totalFreq<<" "<<x<<endl;
        int leftFreq = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == x){
                leftFreq++;
            }
            int rightFreq = totalFreq - leftFreq;

            if(leftFreq > ceil((i + 1)/2)  && rightFreq > ceil((n - i - 1)/2)){
                return i;
            }
        }

        return -1;
    }
};