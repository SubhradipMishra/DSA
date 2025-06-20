class Solution {
public:
    int beautySum(string s) {
        int totalBeauty = 0;
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            unordered_map<char, int> freq;

            for (int j = i; j < n; ++j) {
                freq[s[j]]++;

                int maxFreq = 0;
                int minFreq = INT_MAX;

                for (auto x  : freq) {
                    maxFreq = max(maxFreq, x.second);
                    minFreq = min(minFreq, x.second);
                }

                totalBeauty += (maxFreq - minFreq);
            }
        }

        return totalBeauty;
    }
};
