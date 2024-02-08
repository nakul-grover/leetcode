class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int n=text.size();
        int m=brokenLetters.size();
        unordered_set<char> stt;
        int count=0;
        for(int i=0;i<m;i++){
            stt.insert(brokenLetters[i]);
        }
        bool flag=true;
        for(int i=0;i<n;i++){
            
            if(stt.find(text[i])!=stt.end()){
                flag=false;
            }
            if(text[i]==' '){
                if(flag==true){
                    count++;
                }
                flag=true;
                continue;
            }
            
        }
         if(flag==true){
            count++;
        }
        return count;
         


    }
};