class Solution {
public:
    int longestPalindrome(vector<string>& words) {
         unordered_map<string, int> count;
    int length = 0;
    bool usedCenter = false;

    // Count frequency of each word
    for (string& word : words) {
        count[word]++;
    }

    for (auto& [word, freq] : count) {
        string rev = string(word.rbegin(), word.rend());

        if (word == rev) {
            // Use as many symmetric pairs as possible
            int pairs = freq / 2;
            length += pairs * 4;
            count[word] -= pairs * 2;
        } else if (count.find(rev) != count.end()) {
            // Use min(freq, count[rev]) asymmetric pairs
            int pairs = min(freq, count[rev]);
            length += pairs * 4;
            count[word] -= pairs;
            count[rev] -= pairs;
        }
    }

    // Check if any symmetric word can be used in the center
    for (auto& [word, freq] : count) {
        if (word[0] == word[1] && freq > 0) {
            length += 2;
            break;
        }
    }

    return length;
    }
};