class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
    prefixSumCount[0] = 1; // base case: subarray starting from index 0
    int prefixSum = 0, count = 0;

    for (int num : nums) {
        prefixSum += num;
        if (prefixSumCount.find(prefixSum - k) != prefixSumCount.end()) {
            count += prefixSumCount[prefixSum - k];
        }
        prefixSumCount[prefixSum]++;
    }

    return count; 
    }
};