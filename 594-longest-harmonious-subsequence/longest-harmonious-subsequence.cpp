class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, j = 0;
        int maxLen = 0;
        int n = nums.size();

        while (j < n) {
            if (nums[j] - nums[i] > 1) {
               
                i++;
            } else {
               
                if (nums[j] - nums[i] == 1) {
                    maxLen = max(maxLen, j - i + 1);
                }
                j++;
            }
        }

        return maxLen;
    }
};
