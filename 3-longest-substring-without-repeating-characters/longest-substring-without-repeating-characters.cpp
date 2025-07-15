class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int n = s.size();
        int i = 0, j = 0, maxLen = 0;

        while (j < n) {
            if (st.find(s[j]) == st.end()) {
                st.insert(s[j]);
                maxLen = max(maxLen, j - i + 1);
                j++;
            } else {
                st.erase(s[i]);
                i++;
            }
        }

        return maxLen;
    }
};
