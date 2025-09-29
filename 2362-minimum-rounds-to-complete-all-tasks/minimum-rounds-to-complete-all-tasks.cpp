class Solution {
public:
   
    int minimumRounds(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        int count = 0;
        for (auto &x : mp) {
            int freq = x.second;
            if (freq == 1) return -1;
            while (freq > 0) {
                if (freq >= 3) {
                    freq -= 3;
                } else {
                    freq -= 2;
                }
                count++;
            }
        }
        return count;
    }
};



