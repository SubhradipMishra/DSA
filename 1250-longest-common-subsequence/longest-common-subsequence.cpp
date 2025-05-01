class Solution {
public:
    // int f (int   i , int  j , string& s , string& t , vector<vector<int>>& dp){
    //     if( i <  0 ||  j < 0 )  return 0 ;
    //     if(dp[i][j]!=-1) return dp[i][j] ; 
    //     if(s[i] == t[j]) return  dp[i][j]  =  1 + f(i-1 ,j -1, s, t ,dp) ;
    //     return dp[i][j]  =  0  + max(f(i-1 ,  j , s, t,dp ) , f(i , j - 1 , s , t ,dp)) ; 
    // }
    int longestCommonSubsequence(string s, string t) {
        int n =  s.size() ;
        int m =  t.size() ; 
       vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        vector<int>prev(m+1 , 0 ) ;
        vector<int>cur(m+1 , 0) ; 
        // base case
             
      
        for(int j  =  0;  j <= m ; j++ ) prev[j] = 0  ;
        for(int   i = 1  ;i <= n ;  i++ ) {
            for(int j =  1; j  <=   m ; j++ ) {
                if(s[i-1] == t[j-1] ) cur[j]= 1 + prev[j-1] ;
                else cur[j] = max(prev[j] , cur[j-1]) ; 
            }
            prev = cur ;   ;  
        }


        return prev[m] ; 

    }
};