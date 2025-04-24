class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // vector<vector<uint64_t>> dp(n, vector<uint64_t>(amount + 1, 0));
          vector<uint64_t>prev(amount+1 , 0)  ; 
          vector<uint64_t>curr(amount+1 , 0)  ;
        // Base case for the first coin
        for (int T = 0; T <= amount; ++T) {
            if (T % coins[0] == 0) prev[T] = 1;
        }

        // Main DP transitions
        for (int idx = 1; idx < n; ++idx) {
            for (int T = 0; T <= amount; ++T) {
                uint64_t notTake = prev[T];
                uint64_t take = 0;
                if (coins[idx] <= T)
                    take = curr[T - coins[idx]];
                curr[T] = take + notTake;
            }
            prev  =curr  ;
        }

        return (int)prev[amount];
    }
};
