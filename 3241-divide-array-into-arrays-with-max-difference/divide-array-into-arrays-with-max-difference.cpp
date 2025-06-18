class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size(); 
        int x = n / 3;
        int i = 0;
        int j = 2; 
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end()); 

        while (j < n) { 
           
            if (nums[j] - nums[i] <= k && nums[i+1] - nums[i] <= k && nums[j] - nums[i+1] <= k) {
                vector<int> group;
                for (int k = i; k <= j; k++) {
                    group.push_back(nums[k]);
                }
                ans.push_back(group);
                i += 3;
                j += 3;
            } else {
                
                return {};
            }
        }

        return ans;
    }
};
