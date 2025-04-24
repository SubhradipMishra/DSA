class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s(nums.begin(), nums.end());
        int k = s.size(); // total unique elements
        
        unordered_map<int, int> freq;
        int count = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            freq[nums[right]]++;
            
            while (freq.size() == k) {
                count += (n - right); // all subarrays from left to right...n-1
                freq[nums[left]]--;
                if (freq[nums[left]] == 0)
                    freq.erase(nums[left]);
                left++;
            }
        }
        return count;
    }
};
