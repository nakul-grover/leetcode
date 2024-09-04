class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int n = s.size();
        string temp = "";
        for(int i=n-1;i>=0;i--){
            if(s[i] == ' '){
                while(i>=0 && s[i] == ' '){
                    i--;
                }
                if(temp!=""){
                reverse(temp.begin(),temp.end());
                ans+=temp;
                ans+=" ";
                temp="";
                }
                i++;
            }
            else{
                temp+=s[i];
            }
        }
        reverse(temp.begin(),temp.end());
        ans+=temp;
        n = ans.size();
        if(ans[n-1] == ' '){
            return ans.substr(0,n-1);
        }
        return ans;
    }
};