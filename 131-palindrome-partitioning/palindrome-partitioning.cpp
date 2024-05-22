class Solution {
public:
    bool ispalindrome(string s){
        string temp=s;
        reverse(s.begin(),s.end());
        return temp==s;
}
    void solution(string s,vector<string>temp,vector<vector<string>>&ans){
        if(s.size()==0){
            ans.push_back(temp);
            return;
}
        for(int i=0;i<s.size();i++){
            string x=s.substr(0,i+1);
            string rem=s.substr(i+1);
            if(ispalindrome(x)){
                temp.push_back(x);
                solution(rem,temp,ans);
                temp.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        solution(s,temp,ans);
        return ans;
        
    }
};