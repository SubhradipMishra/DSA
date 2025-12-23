class Solution {
public:
  int helper(int i  ,int j , vector<vector<int>>& grid , vector<vector<int>>& dp){
    if(i < 0 || j <0 || grid[i][j] == 1)  return 0 ; 
    if( i == 0 &&  j == 0 ) return 1 ; 
  
    if(dp[i][j]!=-1) return dp[i][j] ; 
    int down  = helper(i-1 , j , grid ,dp) ; 
    int right = helper(i,j-1,grid, dp) ; 
    return dp[i][j] = down + right ; 
  }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n =  grid.size() ;
        int m =  grid[0].size() ;  

        vector<vector<int>>dp(n+1 , vector<int>(m+1,-1))  ;

        return helper(n-1,m-1,grid,dp) ;
    
    
    
    }
};