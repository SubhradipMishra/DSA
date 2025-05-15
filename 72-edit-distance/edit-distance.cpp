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
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, s, t, dp);
    }
};
