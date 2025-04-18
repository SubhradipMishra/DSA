class Solution {
public:
    int f(int i , int j ,vector<vector<int>>& t  , vector<vector<int>>& dp){
        if(i == t.size()-1) return t[t.size()-1][j] ;
        if(dp[i][j]!=-1) return dp[i][j] ; 
        int d = t[i][j] + f(i+1,j,t,dp) ;
        int dg = t[i][j] + f(i+1,j+1,t,dp) ;
        return dp[i][j] = min(d,dg) ; 
    }
    int minimumTotal(vector<vector<int>>& t) {
        int n =  t.size() ; 
         vector<vector<int>> dp(n, vector<int>(n, -1));

         return f(0,0,t,dp) ;
    }
};