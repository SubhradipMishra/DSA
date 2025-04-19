class Solution {
public:
   bool f(int i, int k, vector<int>& arr, vector<vector<int>>& dp) {
    if (k == 0) return true;
    if (i == 0) return (arr[0] == k);
    if (dp[i][k] != -1) return dp[i][k];

    bool nonTake = f(i-1, k, arr, dp);
    bool take = false;
    if (arr[i] <= k) take = f(i-1, k-arr[i], arr, dp);

    return dp[i][k] = take || nonTake;
}
    bool canPartition(vector<int>& nums) {
        int n  = nums.size();
        int sum  = 0 ; 
        for(int i =  0 ; i <  n ; i++){
            sum+=nums[i] ; 
        } 
        if(sum %2 != 0  )  return false  ;
        int k  = sum/2 ;
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        return f(n-1,k,nums,dp) ;
        
        
            }
};