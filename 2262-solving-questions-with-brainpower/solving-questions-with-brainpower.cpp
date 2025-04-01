class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0);
        
        for (int i = n - 1; i >= 0; i--) {
            int points = questions[i][0];
            int brainPower = questions[i][1];
            int nextIndex = i + brainPower + 1;
            long long solve = points + (nextIndex < n ? dp[nextIndex] : 0);
            long long skip = dp[i + 1];
            dp[i] = max(solve, skip);
        }
        
        return dp[0];
    }
};
