class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();
        int minLen = INT_MAX;
        map<int,int> mp;
        int i = 0;
        int j = 0;

        while (j < n) {
            if (mp.find(cards[j]) == mp.end()) {
                mp[cards[j]] = j;
            } else {
                i = mp[cards[j]] + 1;
                int len = j - mp[cards[j]] + 1;
                minLen = min(minLen, len);
                mp[cards[j]] = j;
            }
            j++;
        }

        return minLen == INT_MAX ? -1 : minLen;
    }
};
