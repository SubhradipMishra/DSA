class Solution {
public:
   int f(int  i  ,  vector<int>&dp){
   if( i == 0 ||  i == 1) return i ; 
    if(dp[i]!=-1) return dp[i] ; 
    return dp[i] = f(i-1,dp) + f(i-2,dp);
   }
    int fib(int n) {
       vector<int>dp(n+1) ; 
     if(n ==0 || n ==1)  return n ;
     dp[0] = 0 ; 
     dp[1] = 1 ; 
     for(int i  = 2 ; i <= n ;i++){
        dp[i] = dp[i-2] + dp[i-1] ;
     }

     return dp[n]; 
    }
};
