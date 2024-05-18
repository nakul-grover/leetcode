class Solution {
public:
    bool isValid(vector<int>&freq,int k){
        if(freq[0]>= k && freq[1] >=k && freq[2]>=k){
            return true;
        }
        return false;
    }
    bool satisfy(string s,int key,int k){
        vector<int>freq(3,0);
        for(int i=0;i<key;i++){
            freq[s[i]-'a']++;
        }
        if(isValid(freq,k)){
            return true;
        };
        int i = key-1;
        int j=s.size()-1;

        while(i>=0){
            freq[s[j]-'a']++;
            freq[s[i]-'a']--;
            j--;
            i--;
            if(isValid(freq,k)){
                return true;
            }
        }
        return false;
        
    }
    int takeCharacters(string s, int k) {
        int low =0;
        int ans=INT_MAX;
        int high =s.size();
        while(low<=high){
            int mid=low+((high-low)/2);
            if(satisfy(s,mid,k)){
                ans=mid;
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
        
    }
};