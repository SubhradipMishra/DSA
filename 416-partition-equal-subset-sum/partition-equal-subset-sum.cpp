class Solution {
public:

    bool helper(vector<int>& arr , int  k, int idx , int sum , vector<vector<bool>>& dp){
        if(sum == k ) return true ; 
        if(idx ==  arr.size()|| sum > k)  return false; 

        if(dp[idx][sum]) return dp[idx][sum] ; 

        bool take = helper(arr , k , idx + 1 , sum +  arr[idx] , dp) ; 
        bool notTake = helper(arr , k , idx + 1 ,sum , dp) ; 

        return dp[idx][sum] = take | notTake ;
    }
    bool canPartition(vector<int>& arr) {
        int n =  arr.size() ; 
        int sum  = 0 ; 
        for(int i  =  0 ;  i < n ;i++){
            sum += arr[i]  ;
        }

        if(sum % 2!= 0 )  return false ;
        int k = sum/2 ;

        vector<vector<int>>dp(n ,vector<int>(k+1 , 0)) ; 

        for(int i =  0 ; i  <  n ; i++) dp[i][0] =  true ; 
        if(arr[0] <= k ) dp[0][arr[0]] = true ; 

        for(int i =  1 ; i < n ; i++){
            for(int s = 1 ; s <= k  ;s++){
                bool nottake = dp[i-1][s];
                bool take = false ; 
                if(s >= arr[i])  take = dp[i-1][s-arr[i]] ; 

                dp[i][s]  =take | nottake ; 
            }
        }

        return dp[n-1][k] ; 
    }
};