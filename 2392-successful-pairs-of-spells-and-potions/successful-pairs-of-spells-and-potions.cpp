class Solution {
public:
    int find(vector<int>& v, long long minPotion) {
        int n = v.size();
        int lo = 0, hi = n - 1, ans = -1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (v[mid] >= minPotion) {   
                ans = mid;
                hi = mid - 1;          
            } else {
                lo = mid + 1;           
            }
        }
        return ans;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = potions.size();
        vector<int> ans;

        for (int spell : spells) {
            long long minPotion = (success + spell - 1) / spell;
            int idx = find(potions, minPotion);
            if (idx == -1) ans.push_back(0);
            else ans.push_back(n - idx);
        }

        return ans;
    }
};
