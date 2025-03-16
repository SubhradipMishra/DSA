class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        
        // Compute prefix sum array
        for (int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
        }
        
        // Edge Case: Check if index 0 is the pivot
        if (nums[n - 1] - nums[0] == 0) return 0;

        // Iterate to find pivot index
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] == nums[n - 1] - nums[i]) {
                return i;
            }
        }

        return -1; // No pivot index found
    }
};
