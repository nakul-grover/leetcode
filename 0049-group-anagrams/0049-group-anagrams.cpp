class Solution {
public:
    unordered_map<string,vector<string>>m;
    void makecode(vector<int>freq,string word){
        string s="";
        for(int i=0;i<freq.size();i++){
            if(freq[i]!=0){
                s=s+to_string(freq[i])+"#";
            }
            else{
                s=s+"#";
            }
        }
        m[s].push_back(word);
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        
        for(int i=0;i<strs.size();i++){
            vector<int>freq(26,0);
            for(int j=0;j<strs[i].size();j++){
                freq[strs[i][j]-'a']++;
            }
            for(int i=0;i<freq.size();i++){
cout<<freq[i]<<" ";}
            cout<<endl;
            
            makecode(freq,strs[i]);
        }
        for(auto i:m){
            ans.push_back(i.second);
            // cout<<i.first<<endl;
        }
        return ans;
    }
};