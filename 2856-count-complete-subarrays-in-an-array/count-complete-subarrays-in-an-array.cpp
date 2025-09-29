class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }
        int k = st.size();
        int i = 0;
        int j = 0;
        long long count = 0;

        unordered_map<int,int> mp;
        while (j < nums.size()) {
            mp[nums[j]]++;
            while (mp.size() == k) {
                count += (n-j);
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }

            j++ ;
            
        }
        return (int)count;
    }
};
