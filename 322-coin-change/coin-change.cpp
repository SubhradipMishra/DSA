class Solution {
public:
    int f(int idx  ,int target , vector<int>& coins,vector<vector<int>>& dp){
        if( idx == 0 ) {
            if(target % coins[0] == 0 ) return target/coins[0] ; 
            else return 1e9 ; 
        }
        if(dp[idx][target]!=-1) return dp[idx][target] ;
        int notTake = 0 + f(idx - 1 ,target, coins,dp ) ;
        int take = INT_MAX ; 
        if(coins[idx] <= target) take = 1 +  f(idx, target-coins[idx] , coins,dp) ;
        return dp[idx][target]=  min(take ,notTake) ;
    }
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size() ; 
        vector<vector<int>>dp(n,vector<int>(amount+1 ,0)) ;

        // base case

        for(int T =  0 ; T  <= amount  ; T++ ){
            if(T % coins[0] == 0 )  dp[0][T] = T/coins[0] ; 
            else dp[0][T]  = 1e9 ; 
        }

        for(int i   =    1 ; i <  n ;  i++ ){
            for(int t  =  0 ; t <= amount ; t++  ) {
                int notTake =  0  + dp[i-1][t] ; 
                int take = INT_MAX ; 
                if(coins[i] <=  t )  take = 1 + dp[i][t - coins[i]] ; 
                dp[i][t] = min(take,notTake) ; 
            }
        }
        int ans  =  dp[n-1][amount] ;
        if(ans >= 1e9)  return -1;
        return ans ; 
    }
};