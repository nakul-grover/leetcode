class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>m;
        int n = s.size();
        int j = 0;
        int ans =0 ;
        for(int i=0;i<n;i++){
            if( m.find(s[i]) == m.end() || m[s[i]] == 0){
                m[s[i]]++;
                ans = max(ans, i-j+1);
            }
            else{
            while(m[s[i]]){
                m[s[j]]--;
                j++;
            }
            m[s[i]]++;
            }
        }
        return ans;
    }
};