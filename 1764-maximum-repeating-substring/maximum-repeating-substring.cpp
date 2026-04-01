class Solution {
public:
    // Z-function
    vector<int> buildZ(string s) {
        int n = s.size();
        vector<int> z(n, 0);
        int l = 0, r = 0;

        for (int i = 1; i < n; i++) {

            if (i <= r) {
                z[i] = min(r - i + 1, z[i - l]);
            }

            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }

            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }
        return z;
    }

    int maxRepeating(string text, string pattern) {

        string temp = pattern;
        int ans = 0;

        while (true) {

            string s = temp + "$" + text;
            vector<int> z = buildZ(s);

            bool found = false;

            for (int i = 0; i < z.size(); i++) {
                if (z[i] == temp.size()) {
                    found = true;
                    break;
                }
            }

            if (!found)
                break;

            ans++;
            temp += pattern; 
        }

        return ans;
    }
};
