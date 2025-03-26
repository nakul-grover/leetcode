class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int rem = grid[0][0]%x;

        vector<int>arr;

        for(int i=0;i<grid.size();i++){
           for(int j=0;j<grid[0].size();j++){
             if(rem != grid[i][j]%x){
                return -1;
             }
            arr.push_back(grid[i][j]);
           }
        }

        sort(arr.begin(),arr.end());
        int mid = arr[(arr.size() -1) /2];

        int count = 0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                 int dev = abs(grid[i][j]-mid);
                 count = count +  (dev / x);
            }
        }

        return count;

        
    }
};