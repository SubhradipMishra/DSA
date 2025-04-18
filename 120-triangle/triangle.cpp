class Solution {
public:
    // int f(int i , int j ,vector<vector<int>>& t  , vector<vector<int>>& dp){
    //     if(i == t.size()-1) return t[t.size()-1][j] ;
    //     if(dp[i][j]!=-1) return dp[i][j] ; 
    //     int d = t[i][j] + f(i+1,j,t,dp) ;
    //     int dg = t[i][j] + f(i+1,j+1,t,dp) ;
    //     return dp[i][j] = min(d,dg) ; 
    // }
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    
    
    vector<int> front(n), cur(n);

    
    for(int j = 0; j < n; j++) 
        front[j] = triangle[n-1][j];

    for(int i = n-2; i >= 0; i--) {
        for(int j = i; j >= 0; j--) {
            int d = triangle[i][j] + front[j];
            int dg = triangle[i][j] + front[j+1];
            cur[j] = min(d, dg);
        }
        front = cur;
    }

    return front[0];
}
};