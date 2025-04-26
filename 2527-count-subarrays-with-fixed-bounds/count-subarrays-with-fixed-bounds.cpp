class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long count = 0;
        int n = nums.size();

        int i = 0;
        int lastMinK = -1;
        int lastMaxK = -1;
        int lastInvalid = -1;

        for (int j = 0; j < n; ++j) {
            if (nums[j] < minK || nums[j] > maxK) {
                lastInvalid = j;
                lastMinK = -1;
                lastMaxK = -1;
            }
            if (nums[j] == minK) lastMinK = j;
            if (nums[j] == maxK) lastMaxK = j;

            if (lastMinK != -1 && lastMaxK != -1) {
                count += max(0, min(lastMinK, lastMaxK) - lastInvalid);
            }
        }

        return count;
    }
};
