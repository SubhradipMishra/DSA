class Solution {
public:
// int f(int i ,  int j  , vector<vector<int>>&dp){
//     if( i == 0 &&  j == 0 )  return 1 ;
//     if(i  < 0 ||  j < 0 ) return   0 ; 
//     if(dp[i][j]!=-1) return dp[i][j] ; 
//     return dp[i][j] = f(i-1 ,j ,dp) + f(i , j-1 , dp) ;
// }
    int uniquePaths(int m, int n) {
              vector<vector<int>> dp(m, vector<int>(n, 0));  // Corrected DP table

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = 1;  // Base case
            } else {
                int up = (i > 0) ? dp[i - 1][j] : 0;
                int left = (j > 0) ? dp[i][j - 1] : 0;
                dp[i][j] = up + left;
            }
        }
    }


              return dp[m-1][n-1] ;

    }
};