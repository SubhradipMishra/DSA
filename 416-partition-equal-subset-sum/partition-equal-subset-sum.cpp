class Solution {
public:

    bool helper(vector<int>& arr , int sum ,int idx , vector<vector<int>>& dp) {
        if(sum == 0)  return true;  
        if(idx == arr.size()) return false ; 
        if(dp[idx][sum]!=-1) return dp[idx][sum] ; 
        bool take = false ; 
        if(arr[idx] <= sum )  take = helper(arr , sum-arr[idx] , idx+1,dp);
        bool nottake = helper(arr , sum , idx+1,dp);

        return dp[idx][sum] =  take | nottake ; 
    }
    bool canPartition(vector<int>& arr) {


     int n = arr.size() ; 

     int sum = 0 ; 
     for(int i  = 0 ; i < n;  i++){
        sum += arr[i] ; 

     }  



     if(sum%2!=0 )  return false ; 

     vector<vector<int>>dp(n , vector<int>(sum+1, -1)) ; 
     return helper(arr , sum/2 ,0,dp); 
    }
};