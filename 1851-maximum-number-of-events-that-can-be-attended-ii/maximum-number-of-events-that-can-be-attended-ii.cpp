class Solution {
public:
    int n;
    vector<vector<int>> memo;

    int nextEventIndex(vector<vector<int>>& events, int curEnd, int start) {
        int lo = start, hi = n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (events[mid][0] > curEnd) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }

    int dfs(int i, int k, vector<vector<int>>& events) {
        if (i == n || k == 0) return 0;
        if (memo[i][k] != -1) return memo[i][k];

        int skip = dfs(i + 1, k, events);
        int nextIdx = nextEventIndex(events, events[i][1], i + 1);
        int take = events[i][2] + dfs(nextIdx, k - 1, events);

        return memo[i][k] = max(skip, take);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        n = events.size();
        memo = vector<vector<int>>(n, vector<int>(k + 1, -1));
        return dfs(0, k, events);
    }
};
