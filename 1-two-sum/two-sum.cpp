class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]] = i;
        }

        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            int rem = target - nums[i];
            if(mp.find(rem) != mp.end() && mp[rem] != i){
                ans.push_back(i);
                ans.push_back(mp[rem]);
                break;
            }
        }

        return ans;
    }
};
