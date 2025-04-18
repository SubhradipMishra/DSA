class Solution {
public:
    // int f(int i , int j ,vector<vector<int>>& t  , vector<vector<int>>& dp){
    //     if(i == t.size()-1) return t[t.size()-1][j] ;
    //     if(dp[i][j]!=-1) return dp[i][j] ; 
    //     int d = t[i][j] + f(i+1,j,t,dp) ;
    //     int dg = t[i][j] + f(i+1,j+1,t,dp) ;
    //     return dp[i][j] = min(d,dg) ; 
    // }
    int minimumTotal(vector<vector<int>>& t) {
        int n =  t.size() ; 
        vector<vector<int>> dp(n, vector<int>(n));
         
         // base case
                for(int j =  0 ; j<  n ;j++){
                    dp[n-1][j]= t[n-1][j] ;
                }

                for(int i  = n-2 ;i>=0 ;i--){
                    for(int j = i ;j >= 0 ;j--){
                        int d = t[i][j] + dp[i+1][j] ;
                        int dg = t[i][j] + dp[i+1][j+1] ;
                        dp[i][j]  = min(d,dg) ;
                        
                    }
                }
         return dp[0][0];
    }
};