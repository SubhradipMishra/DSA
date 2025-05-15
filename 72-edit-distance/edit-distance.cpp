class Solution {
public:
    int f(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        if (i < 0) return j + 1;  // Need to insert all remaining characters of t
        if (j < 0) return i + 1;  // Need to delete all remaining characters of s
        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j]) {
            return dp[i][j] = f(i - 1, j - 1, s, t, dp);  // No operation needed
        } else {
            int ins = f(i, j - 1, s, t, dp);     // Insert
            int del = f(i - 1, j, s, t, dp);     // Delete
            int rep = f(i - 1, j - 1, s, t, dp); // Replace
            return dp[i][j] = 1 + min({ins, del, rep});
        }
    }

    int minDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        // base case

        for(int i =  0 ; i <=  n ; i++ ) dp[i][0] = i ; 
        for(int j =  0  ; j <= m ; j++ ) dp[0][j] = j ; 

        for(int i  = 1 ; i <= n ; i++){
            for(int j =  1 ;j <= m ; j++){
                if(s[i-1] ==  t[j-1] ) dp[i][j] =  dp[i-1][j-1] ;
                else{
                    int ins = dp[i][j-1];     // Insert
                    int del = dp[i-1][j];     // Delete
                    int rep = dp[i-1][j-1];  // Replace
                    dp[i][j] = 1 + min(ins,min(del,rep));
                }
            }
        }

        return dp[n][m] ;
    }
};
