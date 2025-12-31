class Solution {
public:


   
        vector<vector<string>> ans ; 
        vector<string>board ; 

        vector<bool> col, diag1, diag2;

    void helper(int row   , int n ){
        if(row ==  n) {
            
        ans.push_back(board);
        return ; 
        }

        for(int c = 0  ; c <  n ;c++){
            if(!col[c] && !diag1[row-c+n-1] && !diag2[row + c]){
                board[row][c] ='Q' ; 
                col[c] = diag1[row - c + n - 1] = diag2[row + c] = true;
                helper(row+1 ,n );  
                 board[row][c] ='.' ; 
                col[c] = diag1[row - c + n - 1] = diag2[row + c] = false;

            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        
        ans.clear();
        board.assign(n, string(n, '.'));

        col.assign(n,false) ; 

        diag1.assign(2*n-1 , false) ; 
        diag2.assign(2*n-1 , false) ; 

        helper( 0 , n) ; 

        return ans ;  

    }
};