class Solution {
public:
    vector<int> prefixSum;			
    vector<vector<int>> dp;
    int solve(vector<int>& stoneValue,int i,int j)
    {
        if(i==j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        dp[i][j]=0;
        for(int p=i+1;p<=j;p++)
        {
			int l=prefixSum[p]-prefixSum[i],r=prefixSum[j+1]-prefixSum[p];
			if(l<r)		
                dp[i][j]=max(dp[i][j],l+solve(stoneValue,i,p-1));
            else if(l>r)	
                dp[i][j]=max(dp[i][j],r+solve(stoneValue,p,j));
            else	
                dp[i][j]=max(dp[i][j],l+max(solve(stoneValue,p,j),solve(stoneValue,i,p-1)));
        }
        return dp[i][j];
    }
    int stoneGameV(vector<int>& stoneValue)
    {
        dp.resize(stoneValue.size(),vector<int>(stoneValue.size(),-1));
        prefixSum.resize(stoneValue.size()+1,0);
        for(int i=0;i<stoneValue.size();i++)
            prefixSum[i+1]=prefixSum[i]+stoneValue[i];
        return solve(stoneValue,0,stoneValue.size()-1);
    }
};