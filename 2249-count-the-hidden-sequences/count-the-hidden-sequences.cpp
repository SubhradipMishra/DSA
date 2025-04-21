class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long minVal = 0, maxVal = 0, curr = 0;
        for (int diff : differences) {
            curr += diff;
            minVal = min(minVal, curr);
            maxVal = max(maxVal, curr);
        }
        
        long long left = lower - minVal;
        long long right = upper - maxVal;
        
        if (left > right) return 0;
        return (int)(right - left + 1);
    }
};
