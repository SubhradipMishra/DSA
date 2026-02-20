class Solution {
public:

    bool isPossible(vector<vector<char>>& board ,int num ,  int i  , int j ){
        char ch = '0' + num ; 

        for(int row = 0 ; row < 9 ; row++){
            if(board[row][j] ==  ch)  return false ;   
        }
        for(int col =  0 ; col < 9 ; col++){
            if(board[i][col] == ch)  return false ; 
        }

        int sr = (i/3)*3 ; 
        int sc = (j/3)*3 ;
        for(int a = 0 ;a < 3 ;a++){
            for(int b = 0 ; b  < 3; b++){
                if(board[sr + a][sc+b] == ch) return false ; 
            }
        }

        return true ; 
    }
    bool solve(int row , int col , vector<vector<char>>& board){
        if(row == 9 ) return true ; 
        if(col ==  9 )  return solve(row + 1 , 0 , board) ;
        if(board[row][col] != '.') return solve(row , col + 1 , board) ; 

        for(int i =  1 ; i <=  9 ; i++){
            if(isPossible( board , i , row , col)){
                 board[row][col] = '0' +  i ; 
                 if(solve(row , col + 1 , board)) return true ;
                 board[row][col]='.' ;
            }
        }

        return false ; 
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(0,0,board) ; 


    }
};