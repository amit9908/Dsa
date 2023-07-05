class Solution {
public:
    
    bool isSafe(int k , int row , int col ,vector<vector<char>>& board){
          for(int i=0 ; i<9 ; i++){

              if(board[i][col] == k +'0')
              return false;

              if(board[row][i] == k +'0')
              return false;
                  

              if(board[3*(row/3)+i/3][3*(col/3)+i%3] == k +'0')
              return false;   
            
            }

        return true;

   }



    bool solve(vector<vector<char>>& board){
        for(int row = 0 ; row<9 ; row++){
            for(int col = 0 ; col<9 ; col++){
                
                if(board[row][col] == '.'){
                    for(int k=1 ; k<=9 ; k++){
                         if(isSafe(k , row , col ,board)){
                             board[row][col] = k + '0';
                             bool aageKaSolution = solve(board);
                             if(aageKaSolution == true){
                                 return true;
                            }
                             else{
                                 board[row][col] = '.';
                            }
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }



    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

// t.c o(9^m*n)
// s.c o(m*n)