class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>>x;
        vector<vector<int>>y;

        for(int i=0;i<rectangles.size();i++)
        {
            x.push_back({rectangles[i][0],rectangles[i][2]});
            y.push_back({rectangles[i][1],rectangles[i][3]});
        }

        sort(x.begin(), x.end());
        sort(y.begin(),y.end());

        int xCut = 0;
        int yCut = 0;
        
        int maxX = x[0][1];
        int maxY = y[0][1];
        for(int i=1;i<x.size();i++){
             
             if(x[i][0]>= maxX){
                xCut++;
             }
             if(y[i][0] >= maxY){
                yCut++;
             }
             maxX = max(maxX,x[i][1]);
             maxY = max(maxY,y[i][1]);
        }
        cout<<yCut<<endl<<xCut<<endl;

        return xCut >=2 || yCut >=2;

    }
}; 