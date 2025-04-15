class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;

        int i = 0, j = 0, count = 0;
        int p = 1, n = nums.size();

        while (j < n) {
            p *= nums[j];

            while (p >= k && i <= j) {
                p /= nums[i];
                i++;
            }

            // Now p < k, and all subarrays from i to j are valid
            count += j - i + 1;
            j++;
        }

        return count;
    }
};
