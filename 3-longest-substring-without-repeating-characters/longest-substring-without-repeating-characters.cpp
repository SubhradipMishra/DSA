class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;  
        int n = s.size();
        int i = 0, j = 0;  
        int maxLen = 0;

        while (j < n) {
            if (mp.find(s[j]) == mp.end() || mp[s[j]] < i) {
                maxLen = max(maxLen, j - i + 1);
            } else {
                i = mp[s[j]] + 1;
            }
            mp[s[j]] = j;
            j++; 
        }

        return maxLen;
    }
};
