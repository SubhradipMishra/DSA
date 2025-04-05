class Solution {
public:
    void f(vector<int>& nums, vector<int> ans, int idx, int& total) {
        if (idx == nums.size()) {
            int sum = 0;
            for (int i = 0; i < ans.size(); i++) {
                sum ^= ans[i];
            }
            total += sum;
            return;
        }

        // Exclude current element
        f(nums, ans, idx + 1, total);

        // Include current element
        ans.push_back(nums[idx]);
        f(nums, ans, idx + 1, total);
    }

    int subsetXORSum(vector<int>& nums) {
        int total = 0;
        vector<int> ans;
        f(nums, ans, 0, total);
        return total;
    }
};
