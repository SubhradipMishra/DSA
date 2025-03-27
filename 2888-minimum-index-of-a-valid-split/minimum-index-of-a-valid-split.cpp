

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int, int> freq;
        for (int num : nums) freq[num]++;

        int dominant = -1;
        for (auto& [key, val] : freq) {
            if (val > n / 2) {
                dominant = key;
                break;
            }
        }

        if (dominant == -1) return -1;

        int leftCount = 0, rightCount = freq[dominant];

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == dominant) {
                leftCount++;
                rightCount--;
            }

           if (leftCount > (i + 1) / 2 && rightCount > (n - i - 1) / 2) {
    return i;
}

            }
        

        return -1;
    }
};
