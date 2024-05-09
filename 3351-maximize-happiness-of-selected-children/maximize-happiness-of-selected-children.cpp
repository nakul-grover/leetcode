class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long int ans=0;
        sort(happiness.begin(),happiness.end());
        reverse(happiness.begin(),happiness.end());
        long long int minus=0;
        for(int i=0;i<k;i++){
            if(happiness[i]-minus>0){
            ans+=happiness[i]-minus;
            minus++;
        }
         else{
             break;
         }
    }
             return ans;
             }
};