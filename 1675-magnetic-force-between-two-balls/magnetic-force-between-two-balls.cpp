class Solution {
public:
    bool solve(int mid ,vector<int>positions,int m,int n){
        int lastPosition=positions[0];
        int count = 1;
        for(int i=1;i<n;i++){
            if(abs(positions[i]-lastPosition)>=mid){
                count++;
                lastPosition = positions[i];
            }
            if(count==m)
            {
                return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int maxi=INT_MIN;
        sort(position.begin(),position.end());
        int n=position.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,position[i]);
        }
        int low=0;
        int high =maxi;
        int ans=INT_MIN;
        while(low<=high){
            int mid =low+(high-low)/2;
            if(solve(mid,position,m,n)){
                ans=mid;
                low=mid+1;
            }
            else{ 
                high =mid-1;
            }
        }
        return ans;
    }
};