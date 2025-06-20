class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }

        priority_queue<pair<int, char>> pq;
        for (auto& [ch, count] : freq) {
            pq.push({count, ch}); // Max heap by default in C++
        }

        string ans = "";
        while (!pq.empty()) {
            auto [count, ch] = pq.top();
            pq.pop();
            ans += string(count, ch); // repeat ch count times
        }

        return ans;
    }
};
