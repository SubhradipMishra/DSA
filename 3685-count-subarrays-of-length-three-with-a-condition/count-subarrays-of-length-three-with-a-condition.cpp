class Solution {
public:
    int f(int idx, vector<int>& nums) {
        if (idx + 2 >= nums.size()) { // No valid triplet starting from here
            return 0;
        }
        
        int count = 0;
        if (nums[idx + 1] % 2 == 0 && (nums[idx] + nums[idx + 2]) == (nums[idx + 1] / 2)) {
            count = 1;
        }
        
        return count + f(idx + 1, nums);
    }

    int countSubarrays(vector<int>& nums) {
        return f(0, nums);
    }
};
