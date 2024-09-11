class Solution {
public:
   bool isValid(vector<vector<char>>board,int i ,int j, int n,int m){
       bool row = true;
       bool col = true;
       bool box = true;
       
       char key = board[i][j];

       for(int k = 0; k<m;k++){
        if(board[i][k]==key && k!=j){
            cout<<i<<" "<< k<<" "<<key<<endl;
            row=false;
            break;
        }
       }
       for(int k=0;k<n;k++){
        if(board[k][j]==key && k!=i){
            col=false;
            break;
        }
       }

       int startRow = (i/3)*3;
       int startCol = (j/3)*3;

       for(int i1=startRow;i1<=startRow+2;i1++){
          for(int j1 = startCol;j1<=startCol+2;j1++){
            if(board[i1][j1]==key && (i1!=i && j1!=j)){
                box = false;
                break;
            }
          }
       }
       return row && col && box;


   }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]!='.'){
                    if(!isValid(board,i,j,n,m)){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};