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

                for (auto &[ch, count] : freq) {
                    maxFreq = max(maxFreq, count);
                    minFreq = min(minFreq, count);
                }

                totalBeauty += (maxFreq - minFreq);
            }
        }

        return totalBeauty;
    }
};
