class Solution {
public:
    int helper(int stRow , int stCol , int endRow , int endCol  , vector<vector<int>>& dp){
        if(stRow > endRow || stCol > endCol) return 0 ; 
        if(stRow == endRow  && stCol == endCol) return 1 ;
 if (dp[stRow][stCol] != -1) return dp[stRow][stCol];
          dp[stRow][stCol] = helper(stRow+1,stCol , endRow ,endCol,dp ) + helper(stRow,stCol +1, endRow ,endCol,dp ) ;
 return dp[stRow][stCol];
    }


    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

      return helper(0,0 ,m-1,n-1 ,dp);
    }
};