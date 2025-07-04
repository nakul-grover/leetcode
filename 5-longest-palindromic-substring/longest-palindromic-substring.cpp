class Solution {
public:
    bool dp[1001][1001];
    
    string longestPalindrome(string s) {
        // for(int i=0;i<s.length();i++){
        //     dp[i][i] = true;
        // }
       
        for(int i=s.length()-1;i>=0;i--){
            for(int j=s.length()-1;j>=i;j--){
                if(i == j) dp[i][j] = true;
                else{
                    if(s[i] == s[j]){
                        if(i+1 <= j-1){
                            if(dp[i+1][j-1]) dp[i][j] = true;
                        }
                        else{
                            dp[i][j] = true;
                        }
                    }
                      
                }
            }
        }
        
        int maxdiff = 0;
        pair<int,int> indices = {0,0};
      
        for(int i=0;i<s.length();i++){
            for(int j=0;j<s.length();j++){
                if(dp[i][j]){
                    int diff = j-i;
                    if(diff > maxdiff){
                        maxdiff = diff;
                        indices = {i,j};
                    }
                }
            }
        }
        string ans = "";
        for(int i=indices.first;i<=indices.second;i++){
            ans+=s[i];
        }
        return ans;
        
    }
};