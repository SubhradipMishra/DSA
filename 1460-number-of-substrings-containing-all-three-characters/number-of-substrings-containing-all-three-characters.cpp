class Solution {
public:
    int numberOfSubstrings(string s) {
        string str = "abc"; 
        unordered_map<char, int> mp; 
        
        for (int i = 0; i < 3; i++) {
            mp[str[i]] = -1;
        } 

        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]] = i;  

            if (mp['a'] != -1 && mp['b'] != -1 && mp['c'] != -1) {
                count += 1 + min({mp['a'], mp['b'], mp['c']});
            }
        }

        return count;
    }
};