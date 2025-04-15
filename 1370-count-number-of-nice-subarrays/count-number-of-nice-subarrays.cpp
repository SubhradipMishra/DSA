class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

private:
    int atMost(vector<int>& nums, int k) {
        int i = 0, count = 0, res = 0;
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] % 2 != 0) k--;
            while (k < 0) {
                if (nums[i] % 2 != 0) k++;
                i++;
            }
            res += j - i + 1;
        }
        return res;
    }
};
