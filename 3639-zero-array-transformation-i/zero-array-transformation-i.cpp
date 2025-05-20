class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefix(n + 1);
        for (auto& q : queries){
            prefix[q[0]]--;
            prefix[q[1] + 1]++;
        }
        for (int i = 0, d = 0; i < n; i++){
            d += prefix[i];
            if (max(0, nums[i] + d) != 0) 
                return false;
        }
        return true;
    }
};