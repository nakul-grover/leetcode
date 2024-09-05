class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> ans;
        int i=0;
        while(i<n){
            int currLen = words[i].length();
            int end =i+1;
            while(end<n && currLen + words[end].length()+end-i <=maxWidth){
                currLen+=words[end].length();
                end++;
            }

            int num_Word = end-i;
            int total_Space = maxWidth-currLen;
            int space_bw_words = num_Word== 1 ? total_Space :total_Space/(num_Word-1);
            int extra_space = num_Word==1?0:total_Space%(num_Word-1); 
            string line="";
            if(end==n){
                line = words[i];
                for(int k =i+1;k<end;k++){
                    line = line+' '+words[k];
                    total_Space--;
                }
                if(total_Space>0)
                line+=string(total_Space,' ');
            }
            else{
                for(int k =i;k<end;k++){
                    line = line+words[k];
                    if(line.length()<maxWidth){
                        line+=string(space_bw_words,' ');
                    }
                    if(extra_space>0){
                        line+=' ';
                        extra_space--;
                    }
                }
            }
            i=end;
            ans.push_back(line); 
        }
        return ans;
    }
};