class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> indexMap;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            indexMap[nums[i]].push_back(i);
        }

        for (auto& [num, indices] : indexMap) {
            int size = indices.size();
            for (int i = 0; i < size; ++i) {
                for (int j = i + 1; j < size; ++j) {
                    if ((indices[i] * indices[j]) % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
