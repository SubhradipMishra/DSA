class Solution {
public:
    char findElement(string s, int x, unordered_map<char, int>& mp, unordered_map<char, bool>& used) {
        char ans = ' ';
        for (int i = 0; i < s.size(); i++) {
            if (mp[s[i]] == x && !used[s[i]]) {
                ans = s[i];
                used[s[i]] = true; // mark as used
                break;
            }
        }
        return ans;
    }

    string frequencySort(string s) {
        string ans = "";
        unordered_map<char, int> mp;
        for (char ch : s) {
            mp[ch]++;
        }

        priority_queue<int> pq;
        for (auto x : mp) {
            pq.push(x.second);
        }

        unordered_map<char, bool> used;

        while (!pq.empty()) {
            int x = pq.top();
            pq.pop();
            char el = findElement(s, x, mp, used);
            for (int k = 0; k < mp[el]; k++) {
                ans += el;
            }
        }

        return ans;
    }
};
