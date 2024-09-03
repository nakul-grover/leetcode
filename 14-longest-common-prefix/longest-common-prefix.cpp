class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       string s;
      int  mini=1000;
        for(int i=0;i<strs.size();i++){
            if(strs[i].length()<mini){
                mini=strs[i].length();
                s=strs[i];
            }
}
        int count=0;
        for(int i=0;i<mini;i++){
            for(int j=0;j<strs.size();j++){
                if(s[i]!=strs[j][i]){
                    return s.substr(0,count);
                }
           
}
             count++;
        }       
        return s.substr(0,count);
    
 
        
    }
};