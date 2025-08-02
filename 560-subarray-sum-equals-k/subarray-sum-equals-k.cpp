class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size(); 
        int count = 0; 
        unordered_map<int, int> mp;
        vector<int> pre(n); 

        pre[0] = arr[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + arr[i];
        }

        mp[0] = 1;
        for (int i = 0; i < n; i++) {
            int currSum = pre[i];
            int rem = currSum - k;
            if (mp.find(rem) != mp.end()) {
                count += mp[rem];
            }
            mp[currSum]++;
        }

        return count;
    }
};
