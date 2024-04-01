class Solution {
public:
    vector<int>dp;
    bool solve(string& s,int minJump,int maxJump,int i){
        if(i == s.length()-1)
            return true;
        if(i >= s.length())
            return false;
        if(s[i] == '1')
            return dp[i] = false;
        if(dp[i] != -1)
            return dp[i];
        for(int j = i + minJump;j <= s.length()-1;j++){
            if(j > i + maxJump)
                break;
            if(solve(s,minJump,maxJump,j))
                return dp[i] = true;
        }
        return dp[i] = false;
    }
    bool canReach(string s, int minJump, int maxJump) {
        if(s[s.length()-1] == '1')
            return false;
        int cnt = 0;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '1'){
                cnt++;
                if(cnt >= maxJump) return false;
            }
            else{
                cnt = 0;
            }
        }
        dp = vector<int>(s.length(),-1);
        return solve(s,minJump,maxJump,0);
    }
};