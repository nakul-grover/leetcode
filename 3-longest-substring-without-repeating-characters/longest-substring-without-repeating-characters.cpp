class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>v(256,-1);
        int maxlen=0;int start =-1;
        for(int i=0;i<s.size();i++){
            if(v[s[i]]>start){
                start=v[s[i]];
             
            }
               v[s[i]]=i;
            maxlen=max(maxlen,i-start);
            
            
        }
        return maxlen;
    }
};