class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        // Loop through all possible subsets (2^n possibilities)
        for (int i = 0; i < (1 << n); i++) {
            vector<int> subset;
            
            // For each bit in i, decide whether to include nums[j]
            for (int j = 0; j < n; j++) {
                // Check if the j-th bit of i is set (1) or not (0)
                if (i & (1 << j)) {
                    subset.push_back(nums[j]);
                }
            }
            
            // Add the current subset to the result
            result.push_back(subset);
        }
        
        return result;
    }
};
