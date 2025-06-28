class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> pairs;
        for (int i = 0; i < nums.size(); i++) {
            pairs.push_back({nums[i], i});
        }
        
        sort(pairs.begin(), pairs.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });
        
        vector<pair<int, int>> topK(pairs.begin(), pairs.begin() + k);
        
        sort(topK.begin(), topK.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });
        
        vector<int> res;
        for (auto &p : topK) {
            res.push_back(p.first);
        }
        return res;
    }
};
