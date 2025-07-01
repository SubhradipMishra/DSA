class Solution {
public:
    int possibleStringCount(string word) {
        vector<int> blocks;
        int n = word.size();
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && word[j] == word[i]) {
                j++;
            }
            int blockLen = j - i;
            if (blockLen > 1) {
                blocks.push_back(blockLen);
            }
            i = j;
        }
        int ans = 1; // as-is
        for (auto len : blocks) {
            ans += (len - 1);
        }
        return ans;
    }
};
