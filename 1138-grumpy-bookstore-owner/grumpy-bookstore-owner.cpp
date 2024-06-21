class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int n=customers.size();
        int count = 0;
        int maxi =0;
        int i;
    for(i=0;i<minutes;i++){
        if(grumpy[i]==1)
        count+=customers[i];
}        
        int j=0;
        maxi=count;
        while(i<n){
         if(grumpy[j]==1){
             count-=customers[j];
         }
         if(grumpy[i]==1){
             count+=customers[i];
         }
            maxi=max(maxi,count);
            j++;
            i++;
        }
        int ans =0;
      for(int i=0;i<n;i++){
          if(grumpy[i]==0){
              ans+=customers[i];
          }
      }
      ans+=maxi;
        return ans;
    }
};