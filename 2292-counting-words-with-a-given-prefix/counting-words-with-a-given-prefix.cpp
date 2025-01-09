class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans  = 0;
        int n = words.size();
        for(int i=0;i<n;i++){
            bool isPrefix = true;
            for(int j=0;j<pref.size();j++){
                if(pref[j]!=words[i][j]){
                  isPrefix = false;
                   break;
                }

            }
                            if(isPrefix){
                    ans++;
                }
        }

        return ans;
    }
};