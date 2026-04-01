class Solution {
public:
    int maxRepeating(string text, string pattern) {

        string s = pattern + '$' + text;
        int n = s.length();

        vector<int> z(n, 0);

        int l = 0, r = 0;

        for (int i = 1; i < n; i++) {

            if (i <= r) {
                int k = i - l;
                z[i] = min(r - i + 1, z[k]);
            }

            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }

            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }

        int m = pattern.size();
        int maxCount = 0;

        for (int i = m + 1; i < n; i++) {

            int count = 0;
            int j = i;

            while (j < n && z[j] >= m) {
                count++;
                j += m;
            }

            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};
