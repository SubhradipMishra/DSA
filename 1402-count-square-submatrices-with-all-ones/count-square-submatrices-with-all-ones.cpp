class Solution {
public:
    int n ,  m ; 
    vector<vector<int>> dp;  
    int helper(int  i ,  int j  ,  vector<vector<int>>& matrix){
        if(i >=m || j >= n )return  0 ; 
        if (dp[i][j] != -1) return dp[i][j];
        if(matrix[i][j] == 0 ) return  0 ; 

        int down = helper(i+1 , j , matrix) ; 
        int dig = helper(i+1 ,j +1 , matrix); 
        int right = helper(i,j+1 ,  matrix ) ; 

        return dp[i][j] = 1 + min({down, right, dig}) ; 
    }
    int countSquares(vector<vector<int>>& matrix) {
          m = matrix.size();
        n = matrix[0].size();
        dp.assign(m, vector<int>(n, -1));
        int total = 0 ;  
        for(int i =  0 ; i  < m ; i++){
            for(int  j  = 0  ; j < n ; j++){
                total +=  helper(i , j  , matrix) ; 
            }
        }

        return total;
    }
};