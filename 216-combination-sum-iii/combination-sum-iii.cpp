class Solution {
public:
    void solve(int k,int n ,int i,vector<int>temp,vector<vector<int>>&ans,int sum){
        if(k<0 || i>9){
            return;
        }
        if(sum == n && k == 0){
          ans.push_back(temp);
          return;
        }
        for(int index = i+1;index<=n;index++){
            if(sum+index > n){
                break;
            }
            temp.push_back(index);
            solve(k-1,n,index,temp,ans,sum+index);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        vector<vector<int>>ans;
        solve(k,n,0,temp,ans,0);
        return ans;
    }
};