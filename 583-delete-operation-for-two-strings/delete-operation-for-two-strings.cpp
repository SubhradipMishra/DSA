class Solution {
public:
    // int f(int i  , int j , string& s , string& t , vector<vector<int>>&dp){
    //     if(i < 0  || j < 0 )  return 0  ; 
    //     if(dp[i][j] !=-1) return dp[i][j] ; 
    //     if(s[i] == t[j] ) return dp[i][j] = 1 + f(i-1,j-1,s,t,dp) ;
    //     else return dp[i][j] =  0 + max(f(i-1,j,s,t,dp) ,f(i,j-1,s,t,dp));
    // }
    int minDistance(string s, string t) {
        int n  = s.size() ; 
        int m  = t.size() ; 
        // vector<vector<int>>dp(n+1 , vector<int>(m+1 , 0)) ; 
        // for(int  i = 0 ; i <=  n ; i++ ) dp[i][0] = 0 ; 
        // for(int j =  0 ; j <= m ;j++ )dp[0][j] = 0 ; 

        vector<int>prev(m+1,0);
        vector<int>curr(m+1 , 0 );

        for(int i = 1 ; i<= n; i++){
            for(int j = 1 ; j<=m ;j++){
                if(s[i-1]==t[j-1]) curr[j]  =  1 + prev[j-1]; 
                else curr[j] = 0 +  max(prev[j]  ,curr[j-1])  ;
            }
            prev = curr ;
        }
        
        int lcs = curr[m] ; 
        int ans = (n + m) - (2*lcs) ;
        return ans ; 
    }
};