class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>ans; 
        for(int x  : nums){
            if(mp.find(x) != mp.end()) ans.push_back(x);
            else mp[x]++;
        }

        return ans ; 
    }
};