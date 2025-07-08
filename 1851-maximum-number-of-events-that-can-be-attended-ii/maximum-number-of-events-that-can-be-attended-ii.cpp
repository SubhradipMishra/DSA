class Solution {
public:
    int n;

    // Binary search to find the next event that starts after current event's end
    int nextEventIndex(vector<vector<int>>& events, int curEnd, int start) {
        int lo = start, hi = n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (events[mid][0] > curEnd) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end()); // sort by start day
        n = events.size();

        // dp[i][j] = max value by attending up to j events starting from i-th event
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = n - 1; i >= 0; --i) {
            for (int j = 1; j <= k; ++j) {
                int skip = dp[i + 1][j];

                int nextIdx = nextEventIndex(events, events[i][1], i + 1);
                int take = events[i][2] + dp[nextIdx][j - 1];

                dp[i][j] = max(skip, take);
            }
        }

        return dp[0][k];
    }
};
