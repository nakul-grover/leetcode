class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
    
     long long  int sum = 0;
     int n= chalk.size();

      for(int i=0;i<n;i++){
        sum+=chalk[i];
      }

      while(k>=sum){
        k = k-sum;
      }

      for(int i=0;i<n;i++){
        if(k<chalk[i]){
            return i;
        }
        k-=chalk[i];
      }
      
      return -1;
        
    }
};