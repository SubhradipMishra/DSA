class Solution {
public:
    int f(int i, int j, vector<vector<int>>& grid , vector<vector<int>>& dp) {
        if (i == 0 && j == 0) return grid[0][0]; 
        if (i < 0 || j < 0) return INT_MAX; 
        if(dp[i][j] !=-1) return dp[i][j] ;

        int left = f(i - 1, j, grid,dp);
        int up = f(i, j - 1, grid,dp);

        return dp[i][j] = grid[i][j] + min(left, up);
    }

    int minPathSum(vector<vector<int>>& matrix) {
        int n =  matrix.size() ; 
        int m = matrix[0].size()  ;
     vector<vector<int>> dp(n, vector<int>(m, 0)); // Initialize a DP table to store minimum path sums

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0)
                dp[i][j] = matrix[i][j]; // If we are at the top-left corner, the minimum path sum is the value at (0, 0)
            else {
                // Calculate the minimum path sum considering moving up and moving left
                int up = matrix[i][j];
                if (i > 0)
                    up += dp[i - 1][j]; // Include the minimum path sum from above
                else
                    up += 1e9; // A large value if moving up is not possible (out of bounds)

                int left = matrix[i][j];
                if (j > 0)
                    left += dp[i][j - 1]; // Include the minimum path sum from the left
                else
                    left += 1e9; // A large value if moving left is not possible (out of bounds)

                // Store the minimum path sum in dp[i][j]
                dp[i][j] = min(up, left);
            }
        }
    }

    // The final result is stored in dp[n-1][m-1], which represents the destination
    return dp[n - 1][m - 1];
    }
};
