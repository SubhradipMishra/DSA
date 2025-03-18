class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0, maxLen = 0, n = nums.size();

        while (j < n) {
            if (nums[j] == 1) {
                j++;
            } 
            else {
                if (k > 0) {
                    k--;
                    j++;
                } 
                else {
                    if (nums[i] == 0) k++;
                    i++;
                }
            }

            maxLen = max(maxLen, j - i); 
        }

        return maxLen;
    }
};
