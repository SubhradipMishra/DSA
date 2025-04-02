class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        
        vector<int> prefixMax(n);
        prefixMax[0] = nums[0];

        for (int i = 1; i < n; i++)
            prefixMax[i] = max(prefixMax[i - 1], nums[i]);

        for (int j = 1; j < n - 1; j++) { 
            for (int k = j + 1; k < n; k++) {
                long long value = (1LL * prefixMax[j - 1] - nums[j]) * nums[k]; 
                ans = max(ans, value);
            }
        }
        return ans;
    }
};
