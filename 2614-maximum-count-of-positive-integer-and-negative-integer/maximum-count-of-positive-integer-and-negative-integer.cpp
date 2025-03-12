class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1, firstNonNeg = n;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= 0) {
                firstNonNeg = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        int cn = firstNonNeg;

        left = 0, right = n - 1;
        int firstPos = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > 0) {
                firstPos = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        int cp = n - firstPos;

        return max(cp, cn);
    }
};
