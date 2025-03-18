class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(); 
        int maxLen = 0;  
        int i = 0, j = 0;  
        int x = 1; 
        int len = 0;

        while (j < n) {
            if (nums[j] == 1) {
                len++;
            } else {
                if (x > 0) {
                    x--; 
                } else {
                 
                    while (nums[i] == 1) {
                        len--;
                        i++;
                    }
                    i++; 
                }
            }
            maxLen = max(maxLen, len);
            j++;
        }
        
        return maxLen == n ? maxLen - 1 : maxLen; 
    }
};
