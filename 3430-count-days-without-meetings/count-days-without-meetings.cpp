class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
     sort(meetings.begin(),meetings.end());
     int ans = 0;
     int n = meetings.size();
     int maxi = meetings[0][1];
     for(int i=1;i<n;i++){
        if(meetings[i][0]> maxi){
            ans+= meetings[i][0]- maxi-1;
        }
        maxi = max(meetings[i][1],maxi);
     }
      return ans + days-maxi + meetings[0][0]-1;
    }
};
