class Solution {
public:
    int romanToInt(string s) {
       
       unordered_map<char,int>mp;
       mp['I'] = 1;
       mp['V'] = 5;
       mp['X'] = 10;
       mp['C'] = 100;
       mp['L'] = 50;
       mp['M'] = 1000;
       mp['D'] = 500;

       int n = s.size();
       
       int ans = 0;
       ans += mp[s[0]];
       for(int i=1;i<n;i++){
         if(mp[s[i]]>mp[s[i-1]]){
           ans+=mp[s[i]];
           ans-= 2*mp[s[i-1]];
         }
         else{
         ans+=mp[s[i]];
         }
       }

       return ans;
    }
};