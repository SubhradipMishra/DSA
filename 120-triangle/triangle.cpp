class Solution {
public:

    int helper(int i , int   j , int n  , vector<vector<int>>& triangle , vector<vector<int>>& dp){

        if(i == n-1 ) return triangle[i][j] ; 
        if(dp[i][j]!=-1) return dp[i][j] ; 
        int digo = triangle[i][j] + helper(i + 1  ,  j+1 , n , triangle,dp) ; 
        int down = triangle[i][j] + helper(i + 1  ,  j , n , triangle , dp) ; 

        return dp[i][j] = min(digo , down) ;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size() ;
        vector<vector<int>>dp(n , vector<int>(n,0)) ;

    // base case
    
    for(int j   = 0  ; j  < n ; j++){
        dp[n-1][j] = triangle[n-1][j] ;
    }

    for(int i   =  n-2 ; i>= 0 ; i--){
        for(int j =  i ; j >= 0 ; j--){
            int down = dp[i+1][j]  + triangle[i][j]  ;  
            int digo = dp[i+1][j+1] + triangle[i][j] ;

            dp[i][j] = min(down , digo) ;  
        }
    }

    return dp[0][0] ;
    }
};