class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
     int count=0;
        int sum=0;
     unordered_map<int,int>m;
        
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
nums[i]=0;
            }
            else{
                nums[i]=1;
            }
        }
         m[0]=1; 
        for(int i=0;i<n;i++){
            sum+=nums[i];
           if(m.find(sum-k)!=m.end()){
                  count+=m[sum-k];
              }
            
              m[sum]++;
      
        }
        return count;
        
            
        }
            
    
};