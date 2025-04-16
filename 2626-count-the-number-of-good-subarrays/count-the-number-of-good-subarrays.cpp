#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long total_pairs = 0;
        long long result = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            total_pairs += freq[nums[right]];
            freq[nums[right]]++;

            while (total_pairs >= k) {
                result += nums.size() - right;
                freq[nums[left]]--;
                total_pairs -= freq[nums[left]];
                left++;
            }
        }

        return result;
    }
};
    