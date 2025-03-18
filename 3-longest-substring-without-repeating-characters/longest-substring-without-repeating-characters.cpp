class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;  
        int n = s.size();
        int maxLen = 0; 
        unordered_set<char> se;
        int l = 0;

        for (int r = 0; r < n; r++) {
            while (se.find(s[r]) != se.end()) {  
                se.erase(s[l]);
                l++;
            }
            se.insert(s[r]);
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};
