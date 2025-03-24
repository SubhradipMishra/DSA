class Solution {
public:
int f(int idx  , vector<int>& a , vector<int>& dp){
    if(idx == 0 ) return   a[idx] ;
    if(idx <0 ) return  0 ;
    if(dp[idx]!=-1) return dp[idx] ;
    int pick = a[idx] + f(idx -2 ,a,dp);
    int notPick = 0+ f(idx -1 ,a,dp);
    return dp[idx]  =max(pick ,notPick) ;
}
    int rob(vector<int>& a) {
        int n = a.size() ; 
        vector<int>dp(n,-1) ; 
        return f(n-1,a,dp);
    }
};