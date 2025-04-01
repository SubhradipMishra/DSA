class Solution {
public:
    long long f(int i, vector<long long>& dp, vector<vector<int>>& questions) {
        if (i >= questions.size()) return 0;
        if (dp[i] != -1) return dp[i];

        int points = questions[i][0];
        int brainPower = questions[i][1];

        long long solve = points + f(i + brainPower + 1, dp, questions);
        long long skip = f(i + 1, dp, questions);

        return dp[i] = max(solve, skip);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, -1);
        return f(0, dp, questions);
    }
};
