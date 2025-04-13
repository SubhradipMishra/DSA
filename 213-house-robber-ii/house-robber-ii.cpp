class Solution {
public:
    int robLinear(vector<int>& nums, int start, int end, vector<int>& dp) {
        if (start > end) return 0;
        if (dp[start] != -1) return dp[start];

        int robCurrent = nums[start] + robLinear(nums, start + 2, end, dp);
        int skipCurrent = robLinear(nums, start + 1, end, dp);

        return dp[start] = max(robCurrent, skipCurrent);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        // Exclude first house
        vector<int> dp1(n, -1);
        int rob1 = robLinear(nums, 1, n - 1, dp1);

        // Exclude last house
        vector<int> dp2(n, -1);
        int rob2 = robLinear(nums, 0, n - 2, dp2);

        return max(rob1, rob2);
    }
};
