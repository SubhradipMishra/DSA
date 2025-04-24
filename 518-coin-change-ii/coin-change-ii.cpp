class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<uint64_t>> dp(n, vector<uint64_t>(amount + 1, 0));

        // Base case for the first coin
        for (int T = 0; T <= amount; ++T) {
            if (T % coins[0] == 0) dp[0][T] = 1;
        }

        // Main DP transitions
        for (int idx = 1; idx < n; ++idx) {
            for (int T = 0; T <= amount; ++T) {
                uint64_t notTake = dp[idx - 1][T];
                uint64_t take = 0;
                if (coins[idx] <= T)
                    take = dp[idx][T - coins[idx]];
                dp[idx][T] = take + notTake;
            }
        }

        return (int)dp[n - 1][amount];
    }
};
