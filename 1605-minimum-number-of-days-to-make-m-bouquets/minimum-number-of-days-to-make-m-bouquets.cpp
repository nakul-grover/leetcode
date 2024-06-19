class Solution {
public:
    bool myFunc(vector<int>& bloomDay, int m, int k , int mid){
        int count = 0;
        for(int i = 0; i < bloomDay.size() ; i ++){
            if(bloomDay[i] > mid){
                count = 0;
            }     
            if(bloomDay[i] <= mid){
                count++;
            }
            if(count == k){
                count = 0;
                m--;
            }
            if(m == 0) 
                return true;  
    }    
      return false;
}    

    int minDays(vector<int>& bloomDay, int m, int k) {
        int max = *max_element(bloomDay.begin(), bloomDay.end());
        int min = 0 ;
        int mid = 0 ;
        int ans =-1 ;
        while(min <= max){
            mid = (min + max)/2;
            if(myFunc(bloomDay, m, k , mid)){
                ans = mid;
                max = mid -1;
            }
            else{
                min = mid + 1;
            }
        }
        return ans;
    }
};